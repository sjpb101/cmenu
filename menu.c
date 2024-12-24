//#######################################################################
//   NAME:       toolbox.txt
//   FUNCTION:   Main menu
//   INPUT:      NIL
//   OUTPUT:     NIL
//   LINKS:      NIL
//   AUTHOR:     Steven Bowell
//   DATE:       Dec 24
//   CHANGES:    NIL
//   NOTES:      NIL
//#########################################################################

// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// SYMBOLIC CONSTANTS

// FUNTION HEADERS

void add_int(void);
void rand_num(void);
int rnd(int range);
void seedrnd(void);
void pointer_math(void);
void print_string(void);

// GLOBAL VARIABLES

//MAIN
int main()
{
    char c;
    int done;
    char array[] = "Hello!\n";
    char *a,*e;

    done = 0;

    while(!done)
    {
        printf("\n****************************************\n");
        printf("*      MAIN MENU                       *\n");
        printf("****************************************\n");
        printf("*   a - Add numbers\n");
        printf("*   b - Random numbers\n");
        printf("*   c - Print array and address\n");
        printf("*   d - Pointer maths\n");
        printf("*   e - exit\n");
        printf("*   f - Display string using pointer\n");
        printf("****************************************\n");
        printf("\n Type your menu choice: ");
        c = getchar();
        fflush(stdin);
        switch(c)
        {
            case 'a':
                // call function
                add_int();
                break;
            case 'b':
                // call function
                printf(" call random number function\n");
                rand_num();
                break;
            case 'c':
                printf("%s", array);
                a = array;
                e = &array[1];
                printf("Array 'array' is %i bytes long and lives at %p address. \n", sizeof(array),a);
                printf(" Second element is %i bytes long and lives at %p address. \n", sizeof(array[1]), e);
                break;
            case 'd':
                pointer_math();
                break;
            case 'e':
            printf(" Exiting Menu\n");
                done = 1;
                break;
                // exit switch and loop
            case 'f':
                // call function
                print_string();
                break;
            default:
                printf("That is not a valid selection, try again\n");
        } 
    }
    return(0);
}

// FUNCTIONS

void add_int(void)
{
    // local variables
    int myval1;
    int myval2;
    int sum;
    char num[4];

    printf("Enter a number from 0 to 9: ");
    gets(num);
    myval1=atoi(num);
    printf("Enter another number from 0 to 9: ");
    gets(num);
    myval2 = atoi(num);
    sum = myval1+myval2;
    printf("The sum of %i + %i is %i\n", myval1, myval2, sum);
}

void rand_num(void)
{
    int x;
    int reps;
    char num[2];

    seedrnd();
    printf("Enter a number from 0 to 9: ");
    gets(num);
    reps=atoi(num);
    for(x=0;x<reps;x++)
        printf("%d\t",rnd(10));
}

int rnd(int range)
{
    int r;
    r = rand()%range;
    return(r);
}

void seedrnd(void)
{
    
    /*
    int seed;
    char s[6];
    printf("Enter a random number seed (2 - 65000):");
    seed = (unsigned)atoi(gets(s));
    srand(seed);*/

    srand((unsigned)time(NULL));
}

void pointer_math(void)
{
    short int array[] = {2,3,4,7,9};
    short int *pa;
    int x;

    for(x=0;x<5;x++)
    {
        pa = &array[x];
        printf("array[%i] at %p = %i\n",x,pa,array[x]);
    }
    pa = array;
    for(x=0;x<5;x++)
    {
        printf("array[%i] at %p\n",x,pa);
        pa++;
    }

}

void print_string(void)
{
    char sMy[31];
    char *pMy;
    /* With an array of 31, maximum of 30 characters as last Character is a \0*/
    printf("Input a string then press return (Max 30 Characters):");
    gets(sMy);              /* gets a string from input */
    printf("\n You typed %i Characters :  ",strlen(sMy));
    pMy = sMy;              /* initialise pointer */
    // while(*pMy != '\0')     /* \0 is end of string character*/
    while(*pMy)
    {
        //putchar(*pMy);
        //pMy++;
        putchar(*pMy++);        /* optimised */
    }
    printf("\n");
}