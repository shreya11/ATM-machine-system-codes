#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include<iostream>
using namespace std;
   
struct kotakMahindra                  // Structure kotak mahindra defined for kotak mahindra bank.
{
  struct kotakMahindra *next;        
  //struct kotakMahindra *temp;
  int AccountNo, PIN;
  char userName[20];                 
  float currBal;
} *head = NULL, *temp;		    

void createFile_kotak ()                  // createfile_kotak function created for the database.
{
  int value;
  char ch;

  do
    {
      if (head == NULL)                    // Here linked list is created of user's information for kotak mahindra bank.
	{
	  temp = head;
	  temp =(struct kotakMahindra *) malloc (sizeof (struct kotakMahindra));

	  printf ("\nEnter the account number: ");
	  scanf ("%d", &temp->AccountNo);
	  printf ("\nEnter the username: ");
	  scanf ("%s", temp->userName);
	  printf ("\nEnter the PIN number: ");
	  scanf ("%d", &temp->PIN);
	  printf ("\nEnter the Current balance in user's account: ");
	  scanf ("%f", &temp->currBal);
	  temp->next = NULL;
	  head = temp;
	}

      else
	{
	  temp->next =(struct kotakMahindra *) malloc (sizeof (struct kotakMahindra));
	  temp = temp->next;
	  printf ("\nEnter the account number: ");
	  scanf ("%d", &temp->AccountNo);
	  printf ("\nEnter the username: ");
	  scanf ("%s", temp->userName);
	  printf ("\nEnter the PIN number: ");
	  scanf ("%d", &temp->PIN);
	  printf ("\nEnter the Current balance in user's account: ");
	  scanf ("%f", &temp->currBal);
	  temp->next = NULL;
	  //head=temp;

	}
      FILE *fp;                                // file kotak.dat created in append mode.
      fp = fopen ("KOTAk.dat", "a+");

      if (fp != NULL)
	{
	  fprintf (fp, "\n  Account Number : %d\n", temp->AccountNo);
	  fprintf (fp, "\n User Name       :%s\n", temp->userName);
	  fprintf (fp, "\n PIN number      :%d\n", temp->PIN);
	  fprintf (fp, "\n Current balance :%f\n", temp->currBal);

	  fclose (fp);
	}
      printf ("\nDo you want to continue?(y/n) ");
      scanf ("%s", &ch);
    }
  while (ch == 'y' || ch == 'Y');
}

void
display_kotak ()
{
  FILE *fp;
  fp = fopen ("KOTAk.dat", "r");	// read mode

  if (fp == NULL)
    {
      perror ("Error while opening the file.\n");
      exit (EXIT_FAILURE);
    }

  char ch;
  while ((ch = fgetc (fp)) != EOF)
    printf ("%c", ch);
  fclose (fp);

}

struct HDFC  // Structure hdfc created
{
  struct HDFC *next1;
 
   char fd1[10],fd2[10],fd3[4];
	float fd4;
	struct HDFC*next3;
	struct HDFC*previous3;
  //struct kotakMahindra *temp;
  int AccountNo1, PIN1;
  char userName1[20];
  float currBal1;
} *head1 = NULL, *temp1, *head2, *temp2;
struct HDFC*head3=NULL;
struct HDFC*curr3=NULL;

void createFile_HDFC ()  // function createfile_HDFC created, for creating the database.
{
  int value1;
  char ch1;
  //struct kotakMahindra *temp;



  do
    {
      if (head1 == NULL)
	{

	  head1 = (struct HDFC *) malloc (sizeof (struct HDFC));// information of all users stored as a singly  linked list.
	  temp1 = head1;
	  printf ("\nEnter the account number: ");
	  scanf ("%d", &temp1->AccountNo1);
	  printf ("\nEnter the username: ");
	  scanf ("%s", temp1->userName1);
	  printf ("\nEnter the PIN number (4 digit): ");
	  scanf ("%d", &temp1->PIN1);
	  printf ("\nEnter the Current balance in user's account: ");
	  scanf ("%f", &temp1->currBal1);
	  temp1->next1 = NULL;
	  head1 = temp1;
	}

      else
	{

	  temp1->next1 = (struct HDFC *) malloc (sizeof (struct HDFC));
	  temp1 = temp1->next1;
	  printf ("\nEnter the account number: ");
	  scanf ("%d", &temp1->AccountNo1);
	  printf ("\nEnter the username: ");
	  scanf ("%s", temp1->userName1);
	  printf ("\nEnter the PIN number (4 digit): ");
	  scanf ("%d", &temp1->PIN1);
	  printf ("\nEnter the Current balance in user's account:");
	  scanf ("%f", &temp1->currBal1);
	  temp1->next1 = NULL;
	  //head=temp;

	}

      FILE *fp1;
      fp1 = fopen ("HDFC.dat", "a"); // file HDFC created and stored the data of singly linked list

      if (fp1 != NULL)
	{
	  fprintf (fp1, "%d\n", temp1->AccountNo1);
	  fprintf (fp1, "%s\n", temp1->userName1);
	  fprintf (fp1, "%d\n", temp1->PIN1);
	  fprintf (fp1, "%f\n", temp1->currBal1);

	  fclose (fp1);
	}
      printf ("\nDo you want to add more accounts to the HDFC bank?(y/n) ");
      scanf ("%s", &ch1);
    }
  while (ch1 == 'y' || ch1 == 'Y');
}




void
display_HDFC () // display_HDFC function created to display the data from file to the terminal.
{
  FILE *fp;
  fp = fopen ("HDFC.dat", "r");	// read mode

  if (fp == NULL)
    {
      perror ("Error while opening the file.\n");
      exit (EXIT_FAILURE);
    }

  char ch;
  while ((ch = fgetc (fp)) != EOF)
  printf ("%c", ch);
  fclose (fp);
 

}


void
create_database () // Create_data base function created to enter the information of users.
{
  int a;
  char b;
  do
    {
      printf (" \n For HDFC bank enter : 123 \n For KotkMahindrabank enter : 456");
	printf("\nSelect your bank: ")	;
				// For adding the information of the users of particular bank for the data base,from manager's point of view.
      scanf ("%d", &a);

      if (a == 123)
	{
	  int s;
	  int n;
	printf(" \n  ~~~ Welcome to the HDFC bank ~~~ \n");
	  do
	    {
		CORRECT :
	      printf ("\nselect proper option: \n");
	      printf ("\n1. create file HDFC\n");
	      printf ("\n2. display\n");
	      printf ("\n3.exit\n");
	      printf(" \n selectyour choice : \n ");
	      scanf ("%d", &s);
	      switch (s)

		{
		case 1:
		  {
		    createFile_HDFC ();// createFile_HDFC () function called;
		    break;
		  }

		case 2:
		  {
		    display_HDFC (); //display_HDFC () function called;
		    break;
		  }

		case 3:
		  {
		    break;
		  }
		default:
		printf(" \n Inproper selection \n ");
		printf("\n please select again \n ");
		goto CORRECT ;
		
		}
	      printf
		("\n Do you want to again go to the screen of HDFC bank? \n Enter 1 to continue 0 to exit (1/0) :");
	      scanf ("%d", &n);
	    }
	  while (n == 1);
	}
      else if (a == 456)
	{
	  int s1;
	  int n1;
	  do
	    {
	      printf ("\nselect your choice: \n");
	      printf ("\n1. create KotakMahindra\n");
	      printf ("\n2. display\n");
	      printf ("\n3.exit\n");
	      scanf ("%d", &s1);
	      switch (s1)
		{
		case 1:
		  {
		    createFile_kotak ();
		    break;
		  }

		case 2:
		  {
		    display_kotak ();
		    break;
		  }

		case 3:
		  {
		    break;
		  }
		}
	      printf
		("\nDo you want to enter more information of users into KotakMahindra bank or want to display the list? \n Enter 1 to continue 0 to exit (1/0) :");
	      scanf ("%d", &n1);
	    }
	  while (n1 == 1);
	}
      printf ("do you want add more accounts?(y/n): ");
      scanf ("%s", &b);
    }
  while (b == 'y' || b == 'Y');
}

void hdfc_bank()  // function hdfc_banc created.
{
	char d1[10];
	char d2[10];
	char d3[4];
	float d4;
	char pq[10];
	char z[4];
	int abc;
	float lh;
	char y;
	char rt;
	int hy;
	int fr;
	char hr[4];;
	char fv[4];
	char js;
	char kg;
	
	ifstream k; 
   k.open("HDFC.dat"); 

if (k.is_open())
{

	
   for (int i=0;i<5;i++)// transffering information of a file(which is in a linked list) from a terminal via creation a dummy linked list and stored it.
   {
   			
   		if (curr3==NULL)
   		{
   				head3=(struct HDFC*)malloc (sizeof (struct HDFC));
   			curr3=head3;
   			k >> d1; 
   			strcpy(curr3->fd1,d1);
  
   			k >> d2; 
   			strcpy(curr3->fd2,d2); 
   			k >> d3; 
   			strcpy(curr3->fd3,d3); 
   			k >> d4; 
   			curr3->fd4=d4;
   		 
			curr3->next3=NULL;
		}
		else
		{
			curr3->next3=(struct HDFC*)malloc (sizeof (struct HDFC));
			curr3=curr3->next3;
			k >> d1; 
   			strcpy(curr3->fd1,d1);
   
   			k >> d2; 
   			strcpy(curr3->fd2,d2); 
   			k >> d3; 
   			strcpy(curr3->fd3,d3); 
   			k >> d4; 
   			curr3->fd4=d4;
   		
			curr3->next3=NULL;
		}
	}

   	//k.close();
	
	
}
else
cout<<"fail to open\n\n";

printf(" \n please enter your account number : \n ( note : wrong account number will close the display) \n");
scanf("%s",pq);

for (curr3=head3;curr3!=NULL;curr3=curr3->next3)
	{
		
		cout<<curr3->fd1<<"\n";
		cout<<curr3->fd2<<"\n";
		cout<<curr3->fd3<<"\n";
		cout<<curr3->fd4<<"\n";
	}

for(curr3=head3;curr3!=NULL;curr3=curr3->next3)
	{

	if(strcmp(curr3->fd1,pq)==0) 
		{
		cout<<" \n \n you have successfully enterd your account number \n \n ";
		cout<<" \n hello Mr/Mrs :"<< curr3->fd2<<" \n ";
		TERMINAL:
		cout<<" \n Enter your 4 digit PIN number";
		cin>> z;
			if(strcmp(curr3->fd3,z)==0) 
			{
				cout<<"\n \n \n Hello Mr/Mrs : "<<curr3->fd2<<"\n";
			
				//do
				//	{
						
						cout<< "\n \n successfully entered the PIN number";
						EDIT :
						cout<< "\nselect proper option: ";
						cout<< "\n \t 1. cash withdrwal ";
						cout<< "\n \t 2. Fast cash";
						cout<<" \n \t 3.Account inquiry";
 						cout<<" \n \t 4. Change PIN";
						cout<<" \n \t5. Display the information after editing";
						cout<<" \n Select your choice : \n ";
						cin>>abc;
						switch(abc)
						{
							case 1:
							//do
							//{
								RUJUTA :
								cout<<"\n Enter the amount to withdraw";
								cin>> lh;
	      
								if(lh<=20000 &&  lh<=curr3->fd4)
								{	
									curr3->fd4=curr3->fd4-lh;
									cout<<"  \n Mr/Mrs :"<<curr3->fd2;
									cout<<"\n your new balance is : \n"<<curr3->fd4;

				
								}		
				
								else if (lh >= 20000 &&  lh<=curr3->fd4 )
								{
									cout<< " \n Amount should not be more than 20,000";			
								}
							
								else if( lh < 0 )
								{
									cout<<"  \n Error : Negative amount will not be accepted  ";
								}
								else
								{	
									cout<<" \n balance is not sufficient";				
								}
				
						cout<<" \n press y to re-enter the amount \n";
						cin>> rt;
						if(rt=='y' || rt == 'Y')
						{
							goto RUJUTA ;
						}
						else
						 goto TERMINAL2 ;
						//} while(rt=='y' || rt == 'Y' );

						break;

						case 2:
						//do
						//{
							SLIDE:
			 				cout<<" \n \n withdraw fast cash amount";
			 				cout<<" \n \n Select the amount from below";
			 				cout<<" \n \t  1. 500";
							cout<< " \n \t 2. 1000";
							cout<<" \n  \t 3. 2000";
							cout<<" \n  \t 4. 5000";	
							cout<<"\n Select your choice : ";
							cin>> hy;
							switch(hy)
							{
							case 1:
							if(500 <=curr3->fd4)
							{
								curr3->fd4=curr3->fd4-500;
 								cout<< " \n you have withdrawn rs.500 \n";
								cout<< " \n your new balance is :"<< curr3->fd4;
							}
							else
								cout<< " \n Insufficient balance \n";
							break;

							case 2:						
							if(1000 <=curr3->fd4)
							{
								curr3->fd4=curr3->fd4-1000;
 								cout<< " \n you have withdrawn Rs.1000 \n";
								cout<< " \n your new balance is :"<< curr3->fd4;
							}
							else
								cout<< " \n Insufficient balance \n";
							break;

							case 3:			
							if(2000 <=curr3->fd4)
							{
								curr3->fd4=curr3->fd4-2000;
 								cout<< " \n you have withdrawn Rs.2000\n";
								cout<< " \n your new balance is : "<< curr3->fd4;
							}
							else
								cout<< " \n Insufficient balance \n ";
							break;
				
							case 4:

							if(5000 <=curr3->fd4)
							{
								curr3->fd4=curr3->fd4-5000;
 								cout<< " \n you have withdrawn Rs.5000";
								cout<< " \n your new balance is :"<< curr3->fd4;
							}
							else
								cout<< " \n Insufficient balance ";
							break;
			
							default :
								cout<<"\n Error : Inproper selection ";
								cout<<" \n Please select proper choice :";
								goto SLIDE;
							break;
							} // close  sub switch case
							cout<<" \n Do you want to again fast cash the money ? 1/0";
							cin>>fr;
							if(fr==1)
							{
								goto SLIDE;
							}
							else
							 goto TERMINAL2 ;
							
			
						//}while(fr==1);	// do while loop for fast cash trnsction
					break;

				case 3:
					cout<<"\n Account inquiery :";
					cout<<"\n  \t Hello Mr/Mrs                       : "<<curr3->fd2;
					cout<<"\n  \t Your pin number is                 : "<<curr3->fd3;
					cout<<"\n  \t Current balance in your account is : "<<curr3->fd4;
					cout<<"\n  \t  Your account number is            : "<<curr3->fd1;
			         break;
			
               			case 4:
					cout<<" \n Are you sure you want to change your PIN number y/n ?";
					cin>> kg;
					if(kg== 'y' || kg== 'Y')
					{
						PIN :
						cout<<" \n \n please re-enter enter your old pin number :"; // aiya pin number khoto hoy to b access thay che :(
						cin>> hr;
						if(strcmp(curr3->fd3,hr)==0)
						{
							cout<<" \n please enter your new PIN number: ";
							cin>> fv;
							strcpy(curr3->fd3,fv);
							cout<<"\n your new PIN number is :"<< curr3->fd3;	
			
						}
						else
						{
							cout<<" Incorrect old PIN number \n";
							goto PIN ;
						}	
					}
					else
					goto TERMINAL2;
				break;
			
				case 5:
					cout<<"\n Your information after editing:";
					cout<<"\n \t  Account number :"<<curr3->fd1;
					cout<<"\n \t User name       :"<<curr3->fd2;
					cout<<"\n \t PIN number      :"<<curr3->fd3;
					cout<<"\n \t Current balance :"<< curr3->fd4;
				break;

				default :
					cout<<"\n Inproper choice";
				break;
				}// main switch case pate che.
				TERMINAL2 :	
				cout<<" \n Do you want to edit again in your account y/n ?";
				cin >> js;
				if(js== 'y' || js=='Y')
				{
					goto EDIT ;
				}
				else
				 goto FILE;
				
		
	}//mainif  no bracket pin number walo
	else
	cout<<" incorrect PIN number ";
	goto TERMINAL ;
	
	} // Account number walo if pate che.
	
	} // main for loop pate che. 
	
	k.close(); //  file close
FILE :
	ofstream fwrt;// will over write the new information to the file(edited information)
      fwrt.open("HDFC.dat");
	struct HDFC*temp4=NULL;
      if (fwrt.is_open())
	{
		for (temp4=head3;temp4!=NULL;temp4=temp4->next3)
		{
			fwrt<< temp4->fd1<<"\n";
			fwrt<< temp4->fd2<<"\n";
			fwrt<< temp4->fd3<<"\n";
			fwrt<< temp4->fd4<<"\n";		
			
		}		


	  fwrt.close();
	} 
	

} 
void display_ATM () // display_ATM function created for the display of the main ATM.
{
  char sec;
	char lo;
  int kr;
  char b;
  int d;
  printf
    ("\n ----------------------------------------------------------------------------------- \n ");
//  EDITOR :
	RUB :
  printf (" \n Welcome to the ATM  \n ");
	DREAM :
  printf ("\n In which bank u have your account ? \n ");
  printf ("\n 1. KOTAK ");
  printf ("\n 2. HDFC ");
  printf("Select your choice :  \n ");
  scanf ("%d", &kr);
  switch (kr)
    {
    case 1:
      
	printf ("\n\nwelcome to kotak mahindra bank\n\n");
	//kotak_bank(); // function kotak_bank called
	break;
      
    case 2:
      
	printf ("\n\n ~~~ WELCOME TO THE HDFC BANK ~~~  \n\n");
	hdfc_bank(); //function hdfc_bank called
	break;

	default :
      	cout<<" \n Inproper selection \n ";
	cout<<"\n please select again \n ";
	goto DREAM;
    }
	cout<<" Press Y for the main screen of ATM : \n ";
	if(lo=='y' || lo == 'Y')
	{
		goto RUB;
	}



}


int main () // main created
{
  char ch;
  int l;
	
  do
    {
	BUG:
      printf ("\n \n Select proper option \n");
      printf ("  1. Enter user's information for database  (Bank manager's point of view)");
      printf ("\n  2. Working of ATM machine");
      printf("   \n    Select your choice : ");
      scanf ("%d", &l);
//printf(" \n 3. exit");
      switch (l)
	{
	case 1:
	  create_database ();// function create_database called;
	  break;

	case 2:
	 display_ATM ();// function display_ATM called.
	break;
	
	default:
	cout<<" \n Inproper selection \n ";
	cout<<"\n please select again \n ";
	goto BUG; 
	
	}
	  //case 3:
	  //break;
	
      printf (" \n press y for the main screen?(y/n): \n  ");
      scanf ("%s", &ch);
    }
  while (ch == 'y' || ch == 'Y');


}