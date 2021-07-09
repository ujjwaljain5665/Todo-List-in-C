#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Todo todo;
struct Todo{
    char data[100];
    todo *link;
    int count;
};

todo *start=NULL;

COORD c={0,0};
void gotoxy(int x,int y){
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void seetodo();
void createtodo();
void deltodo();
void addtotodo();
void fixcount();

void main(){
    char choice;
    while(1){
        system("cls");
        system("color 3f");
        gotoxy(40,10);
        printf("Welcome To The ToDo App");
        gotoxy(30,12);
        printf("------------------------------------------");
        gotoxy(30,20);
        printf("------------------------------------------");
        gotoxy(39,14);
        printf("1.See Your ToDo List");
        gotoxy(39,15);
        printf("2.Create Your ToDos");
        gotoxy(39,16);
        printf("3.Delete Your ToDos");
        gotoxy(39,17);
        printf("4.Add To Your ToDos");
        gotoxy(39,18);
        printf("5.Exit");
        gotoxy(39,22);
        printf("Enter Your Choice ? ");
        choice=getche();
        switch(choice){
            case '1':
                seetodo();
                break;
            case '2':
                createtodo();
                break;
            case '3':
                deltodo();
                break;
            case '4':
                addtotodo();
                break;
            case '5':
                exit(0);
        }
    }
    getch();
}

//Function to see todo list.
void seetodo(){
    system("cls");
    int i=15;
    todo *temp;
    temp=start;
    
    if(temp==NULL){
        gotoxy(35,15);
        printf("No ToDos created For Today.");
        getch();
        return;
    }
    while(temp!=NULL){
        gotoxy(35,i);
        printf("%d)",temp->count);
        puts(temp->data);
        fflush(stdin);
        temp=temp->link;
        i++;
    }
    gotoxy(35,i+1);
    printf("Press Any Key To Continue.");
    getch();
}

//Function to create todo list.
void createtodo(){
    char k,c;
    todo *t,*temp;
    int i=1;
    system("cls");
    if(start!=NULL){
        gotoxy(35,15);
        printf("ToDo List already exist...overwrite (Y/N):");
        c=getch();
        if(c=='n' || c=='N'){
            return;
        }
    }
    system("cls");
    start=NULL;
    while(1){
        gotoxy(35,i);
        printf("Want To Add To Your ToDo List (Y/N) ?");
        k=getch();
        if(k=='N' || k=='n'){
            return;
        }
        else{
            if(start==NULL){
                t=(todo *)calloc(1,sizeof(todo));
                start=t;
                gotoxy(35,i+2);
                printf("Add Your ToDO : ");
                fflush(stdin);
                gets(t->data);
                t->count=1;
                start->link=NULL;
            }
            else{
                temp=(todo *)calloc(1,sizeof(todo));
                gotoxy(35,i+2);
                printf("Add Your ToDO : ");
                fflush(stdin);
                gets(temp->data);
                temp->link=NULL;
                t->link=temp;
                t=t->link;
            }
            fixcount();
        }
        i=i+4;
    }
}

//Function to delete todo list.
void deltodo(){
    system("cls");
    int d;
    todo *temp,*temp1;
    temp1=start;
    if(temp1==NULL){
        gotoxy(35,15);
        printf("No ToDos created For Today.");
        getch();
        return;
    }
    temp=start->link;
    gotoxy(35,5);
    printf("Enter The No. Of ToDo You Want Delete:");
    scanf("%d",&d);
    while(1){
        if(temp1->count==d){
            start=start->link;
            gotoxy(35,7);
            printf("ToDo:");
            gotoxy(40,7);
            puts(temp1->data);
            free(temp1);
            fixcount();
            gotoxy(35,10);
            printf("ToDo Successfully Deleted.Press any key to continue");
            getch();
            return;
        }
        if(temp->count==d){
            temp1->link=temp->link;
            gotoxy(35,7);
            printf("ToDo:");
            gotoxy(40,7);
            puts(temp->data);
            free(temp);
            fixcount();
            gotoxy(35,10);
            printf("ToDo Successfully Deleted.Press any key to continue");
            getch();
            return;
        }
        else{
            temp1=temp;
            temp=temp->link;
            if(temp==NULL){
                gotoxy(35,10);
                printf("ToDo doesn't exist.Try Again.");
                getch();
                return;
            }
        }
    }
    getch();
    return;
}

//Function to maintain seriall number.
void fixcount(){
    todo *temp;
    int i=1;
    temp=start;
    while(temp!=NULL){
        temp->count=i;
        i++;
        temp=temp->link;
    }
}

//Function to add to todo list.
void addtotodo(){
    system("cls");
    todo *temp,*temp1,*t;
    int i=1;
    char k;
    temp1=start;
    if(temp1==NULL){
        gotoxy(35,15);
        printf("No ToDos created For Today.");
        getch();
        return;
    }
    while(1){
        gotoxy(35,i);
        printf("Want To Add to your ToDo (Y/N) ?");
        k=getch();
        if(k=='n' || k=='N'){
            return;
        }
        gotoxy(35,i+2);
        printf("Add To Your ToDo:");
        temp=(todo *)calloc(1,sizeof(todo));
        fflush(stdin);
        gets(temp->data);
        temp->link=NULL;
        t=start;
        while(t->link!=NULL){
            t=t->link;
        }
        t->link=temp;
        fixcount();
        i=i+4;
    }
    getch();
}
