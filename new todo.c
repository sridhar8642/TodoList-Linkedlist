#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int found=0,test=0;
typedef struct ToDo todo;
void sort();
struct ToDo
{
    char data[100];

    int count;

    int date;
    int month;
    int year;
    todo *link;

};



int datevalid(int dd,int mm,int yy)
{

if(yy>=2022)
{

if(mm>=1 && mm<=12)
{

if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))

return 1;
else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
return 1;

else if((dd>=1 && dd<=28) && (mm==2))
return 1;

else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
return 1;

else
    return 0;

}
else
{
    return 0;

}
}
else
{
    return 0;

}
}





void fixcount();
todo *start=NULL;

void welcomeUser()
{
    system("color 4F");
    printf("\n\n\n\n\n");
    printf("\t------------------------------------------------------------------------------------------------------\n\n");
    printf("\t#################################### TODO LIST APP ##############################################\n\n");
    printf("\t------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\t\t*******************************WELCOME*******************************\n\n\n\n\n\n\n\n\n\t");
    system("pause");
}

void seeToDo()
{  if(test==0)
  {
        system("cls");
}
    todo *temp;
    temp=start;

    printf("YOUR TODO LIST:\n");
    if(start==NULL)
    {
        printf("\n");
        printf("\nEmpty TODO\n\n");
    }

    while(temp!=NULL)
    {
        printf("%d)",temp->count);
        puts(temp->data);

        fflush(stdin);

        printf("\tDeadline:");

        printf("%d/%d/%d",temp->date,temp->month,temp->year);
        temp=temp->link;
        printf("\n");
    }
    printf("\n\n\n");
    system("pause");
}

void createToDo()
{

    char k;
    char choice;
    char date[50];
    todo *t,*temp;
    t=NULL;

    do
    {
        printf("\n");
        printf("\n****************************ADD YOUR TASK****************************");

        printf("\n");
        if(start==NULL)
        {
            t=(todo *)calloc(1,sizeof(todo));
            start=t;


            printf("*");
            fflush(stdin);
            printf("Enter Task:");
            gets(t->data);

            printf("DUE DATE:");
            fflush(stdin);
            // gets(date);
            // scanf("%d%d%d",&t->date,&t->month,&t->year);
            printf("\nenter date:");
            scanf("%d",&t->date);
            printf("\nenter month:");
            scanf("%d",&t->month);
            printf("\nenter year:");
            scanf("%d",&t->year);
            if(datevalid(t->date,t->month,t->year))
{
    printf("\n");

}
            else
            {

                printf("Invalid date or month or year ");
                free(t);
                start=NULL;
                createToDo();
                found=1;
                return;

                // t=(todo*)malloc(sizeof(todo));
            }
            t->count=1;
            start->link=NULL;
        }
        else
        {
            t=start;
            temp=(todo *)calloc(1,sizeof(todo));


            printf("*");
            fflush(stdin);
            gets(temp->data);
            printf("DUE DATE:");
            fflush(stdin);
            printf("\nenter date:");
            scanf("%d",&temp->date);
            printf("\nenter month:");
            scanf("%d",&temp->month);
            printf("\nenter year:");
            scanf("%d",&temp->year);
            if( datevalid(temp->date,temp->month,temp->year))
            {
                printf("\n");
            }

            else
            {
                printf("Invalid date or month or year ");
                free(temp);
                createToDo();
                return;

            }

            temp->link=NULL;
            while(t->link!=NULL)
            {
                t=t->link;
            }
            t->link=temp;

        }

        sort();
        fixcount();
        printf("Task Added successfully");
        printf("\n");
        printf("\n");
        printf("PRESS Y TO ADD NEW TASK:");
        scanf("\n");
        scanf("%c",&choice);


    }
    while(choice=='Y');
}

void delToDo()
{  if(test==0)
    {
        system("cls");
    }

    int d;
    todo *temp1,*temp;
  int i=0,n;
    seeToDo();
    printf("\nEnter the no of the Todo you want to remove:\n");
    scanf("\n");
    scanf("%d",&d);
    temp1=start;
   while(temp1!=NULL)
  {   i++;
      temp1=temp1->link;
      }
      if(i<d||d<0)
      {
          printf("invalid choice\n");
          test=1;
          free(temp1);
          delToDo();
          return;
      }
    //fixcount();
    temp1=start;
    temp=start->link;

    while(1)
    {
        if(temp1->count==d)
        {
            start=start->link;

            free(temp1);
            fixcount();
            break;
        }
        else if(temp->count==d)
        {

            temp1->link=temp->link;
            free(temp);
            fixcount();
            break;
        }
        else
        {
            temp1=temp;
            temp=temp->link;
        }
    }

    system("pause");
}

void fixcount()
{
    todo *temp;
    int i=1;
    temp=start;
    while(temp!=NULL)
    {
        temp->count=i;
        i++;
        temp=temp->link;
    }

}

void updateToDo()
{
    if(found==0)
    {
        system("cls");
    }
    todo *temp,*t;
    char k;

    printf("\nPress Y TO Add new todo  :");
    fflush(stdin);

    scanf("%c",&k);
    if(k=='Y')
    {

        temp=(todo *)calloc(1,sizeof(todo));
        fflush(stdin);

        printf("ADD NEW TASK...");
        printf("\n");
        gets(temp->data);
        printf("DUE DATE:");
        printf("\nenter date:");
        scanf("%d",&temp->date);
        printf("\nenter month:");
        scanf("%d",&temp->month);
        printf("\nenter year:");
        scanf("%d",&temp->year);
        if( datevalid(temp->date,temp->month,temp->year))
           {
               printf("\n");
           }
        else
        {
            printf("Invalid date or month or year ");
            found=1;
            free(temp);
            updateToDo();
            return;
            //goto h;
        }

        temp->link=NULL;
        t=start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
        sort();
        fixcount();

        printf("Task Added successfully...");
    }
    printf("\n\n");
    system("pause");

}
void sort()
{
    todo *temp1,*temp=NULL;
    temp1=start;

    while(temp1!=NULL)
    {
        temp=temp1->link;

        while(temp!=NULL)
        {
            if(temp1->year>temp->year)
            {
                swap(temp1,temp);
            }
            else if((temp1->year==temp->year)&&(temp1->month>temp->month))
            {
                swap(temp1,temp);
            }
            else if((temp1->year==temp->year)&&(temp1->month==temp->month)&&(temp1->date>temp->date))
            {
                swap(temp1,temp);
            }


            temp=temp->link;

        }
        temp1=temp1->link;
    }
}

void swap(todo *temp1,todo *temp)
{
    int a,b,c;
    char word[100];
    todo *t;

    strcpy(word,temp1->data);

    strcpy(temp1->data,temp->data);
    strcpy(temp->data,word);


    a=temp1->year;
    temp1->year=temp->year;
    temp->year=a;

    b=temp1->date;
    temp1->date=temp->date;
    temp->date=b;

    c=temp1->month;
    temp1->month=temp->month;
    temp->month=c;

}

int main()
{
    int choice,clear=0;
    char opt;
    welcomeUser();
    system("cls");
    createToDo();


    while(1)
    {
        system("color 2F");

       if(clear==0)
       {

            system("cls");
       }
       printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MENU:<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("\n1.See Your ToDo List");

        printf("\n2.Delete Your ToDos");
        printf("\n3.Update Your ToDos");
        printf("\n4.Exit");

        printf("\n\nEnter your choice...............\n");
        scanf("\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            seeToDo();
            break;
        case 2:
            delToDo();
            break;
        case 3:
            system("cls");
            updateToDo();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid choice!!!");
             clear=1;

        }
    }
    return 0;
}


