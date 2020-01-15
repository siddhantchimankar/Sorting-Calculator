#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

void bubbleSort(void);
void swap(int*, int,int);
void selectionSort(void);
void swapSelect(int* ,int ,int* );
void insertionSort(void);
void shift(int*, int,int,int);
void quickSort(void);
void partition(int*,int);

int main()
{
    int c = 0;
    printf("\nSORTING CALCULATOR\n");
    printf("------------------------------>");

    do{
    printf("\n\nPRESS 1 -----> BUBBLE SORT\nPRESS 2 -----> SELECTION SORT\nPRESS 3 -----> INSERTION SORT\nPRESS 4 -----> QUICK SORT\nPRESS 5 -----> EXIT\n");
    scanf("%d",&c);

    switch(c)
    {
        case 1 : bubbleSort();
        break;

        case 2 : selectionSort();
        break;

        case 3 : insertionSort();
        break;

        case 4 : quickSort();
        break;
    }
    }while(c !=5);

    return 0;
}

void bubbleSort(void)
{
    int size = 0;
    int travesty = 0;
    printf("\nEnter length of sequence :\n\n");
    scanf("%d",&size);
    printf("\nUnsorted Array :\n\n");
    int* unsortedArray = (int*)malloc(size*sizeof(int));
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&unsortedArray[i]);
    }

    clock_t t;
    t = clock();

    do{
            travesty = 0;
    for(int i = 0 ; i < size ; i++)
    {
        if(unsortedArray[i] > unsortedArray[i+1])
        {
            travesty++;
            swap(unsortedArray,i,i+1);
        }
    }
    }while(travesty != 0);

    printf("\nSorted Array :\n\n");

    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",unsortedArray[i]);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n\nBubble Sort took %f seconds to execute \n", time_taken);


}

void swap(int* unsortedArray, int a, int b)
{
    int temp = 0;
    temp = unsortedArray[b];
    unsortedArray[b] = unsortedArray[a];
    unsortedArray[a] = temp;
}

void insertionSort(void)
{
    int size = 0;
    printf("\nEnter length of sequence :\n\n");
    scanf("%d",&size);
    printf("\nUnsorted Array :\n\n");

    int* unsortedArray = (int*)malloc(size*sizeof(int));
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&unsortedArray[i]);
    }

    clock_t t;
    t = clock();

    for(int i = 0 ; i < size - 1 ; i++)
    {
    if(unsortedArray[i] >unsortedArray[i+1])
    {
        shift(unsortedArray, i,i+1,size);
    }
    }

    printf("\nSorted Array :\n\n");

    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",unsortedArray[i]);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n\nInsertion Sort took %f seconds to execute \n", time_taken);
}

void shift(int* unsortedArray, int a, int b,int size)
{
    int ind = b;
    int temp = unsortedArray[b];
    int* ptr = &unsortedArray[b];
    int* ptra = &unsortedArray[a];

       for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",unsortedArray[i]);
    }

    printf("\nInitial *ptr : %d\nInitial ind : %d\n",*ptr,ind);

    while(ind>0) {
    if(unsortedArray[b] < *ptra)
    {
        ptr--;
        ptra--;
        ind--;
        printf("\n*ptr : %d\nind : %d\n",*ptr,ind);
    }else{
    break;
    }
    }

    printf("\nFinal *ptr : %d\nFinal ind : %d\n",*ptr,ind);

    printf("\nInitial Array\n");

      for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",unsortedArray[i]);
    }

    for(int i = b ; i > ind ; i--)
    {
        unsortedArray[i] = unsortedArray[i-1];
    }

    unsortedArray[ind] = temp;

    printf("\nFinal Array\n");

    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",unsortedArray[i]);
    }
    printf("\n");

}

void selectionSort(void)
{
    int size = 0;
    int p = 0;
    int min = 0;
    int ind = 0;
    printf("\nEnter length of sequence :\n\n");
    scanf("%d",&size);
    printf("\nUnsorted Array :\n\n");
    int* unsortedArray = (int*)malloc(size*sizeof(int));
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&unsortedArray[i]);
    }

    clock_t t;
    t = clock();

    for(int j = 0 ; j <size; j++)
    {


    int * pos  = &unsortedArray[p];
    min = unsortedArray[p];

    for(int i = p ; i < size ; i++)
    {
        if(unsortedArray[i] < min || unsortedArray[i] ==min)
        {
            ind = i;
            min = unsortedArray[i];
        }

    }

   swapSelect(unsortedArray,ind,&p);
    }


    printf("\nSorted Array :\n\n");

    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",unsortedArray[i]);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n\nSelection Sort took %f seconds to execute \n", time_taken);
}

void swapSelect(int* unsortedArray,int ind,int* ptr)
{
    swap(unsortedArray,ind,*ptr);

    (*ptr)++;
}

void quickSort(void)
{
    int size = 0;
    printf("\nEnter length of sequence :\n");
    scanf("\n%d",&size);
    printf("\nUnsorted Array :\n\n");
    int* unsortedArray = (int*)malloc(size*sizeof(int));
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&unsortedArray[i]);
    }

    clock_t t;
    t = clock();

    partition(unsortedArray,size);



    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n\nQuick Sort took %f seconds to execute \n", time_taken);
}

void partition(int* unsortedArray,int size)
{



   int sortedArray[size];
   int s = 0;
   if(size == 2)
   {
       if(unsortedArray[0] > unsortedArray[1])
       {
           int temp = 0;
           temp = unsortedArray[0];
           unsortedArray[0] = unsortedArray[1];
           unsortedArray[1] = temp;

       }

       for(int i = 0 ; i < 2 ; i++)
       {
           printf("%d ",unsortedArray[i]);
       }

   }else if(size == 1){

   printf("%d ",unsortedArray[0]);
   }else{
       int rsize = 0;
       int lsize = 0;
       int* pivot = &unsortedArray[size -1];

       printf("\nPivot : %d",*pivot);

       for(int i = 0 ; i < size ; i++)
       {
           if(unsortedArray[i] > *pivot)
           {
               rsize++;
           }
       }

        for(int i = 0 ; i < size ; i++)
       {
           if(unsortedArray[i] < *pivot)
           {
               lsize++;
           }
       }

       printf("\nrsize : %d\nlsize : %d\n",rsize,lsize);

       int* rightArray = (int*)malloc(rsize*sizeof(int));
       int* leftArray = (int*)malloc(lsize*sizeof(int));

       int r = 0;
       int l = 0;

        for(int i = 0 ; i < size ; i++)
       {

           if(unsortedArray[i] > *pivot)
           {
               rightArray[r] = unsortedArray[i];
               r++;
           }
       }

       for(int i = 0 ; i < size ; i++)
       {

           if(unsortedArray[i] < *pivot)
           {
               leftArray[l] = unsortedArray[i];
               l++;
           }
       }

       printf("\nRight Array :\n");
       for(int i = 0 ; i < rsize ; i++)
       {
           printf("%d ",rightArray[i]);
       }

       printf("\nLeft Array :\n");
       for(int i = 0 ; i < lsize ; i++)
       {
           printf("%d ",leftArray[i]);
       }

       printf("\nSorted Array :\n\n");


       partition(leftArray,lsize);
       printf("%d ",*pivot);

       partition(rightArray,rsize);

   }

}




