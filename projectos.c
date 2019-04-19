#include<stdio.h>
#include<windows.h>
int main()
{
int i,n,processid[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int brusttime[10],temp,j,arrivaltime[10],waitingtime[10],totaltime[10],turnaroundtime=0,sum=0;
float waitingavg=0,turnaroundavg=0,tsum=0,wsum=0;
system("cls");
printf("\n --  __        ---  --       __  __ |  ||   ___ | /|  --  __ ");
printf("\n|   |__||  |  |___ |   |__| |__ |  ]{__}|    |  |/ | |___|  |");
printf("\n -- |   {__}   ___||__ |  | |__ |__]    |__ _|_             |");
printf("\nEnter the No. of processes :");
scanf("%d",&n);
printf("\n **************shortest job first**********"); 
for(i=0;i<n;i++)
{
printf("\tEnter the burst time of %d process :",i+1);
scanf(" %d",&brusttime[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&arrivaltime[i]);
}
 
 
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(arrivaltime[i]<arrivaltime[j])
{
temp=processid[j];
processid[j]=processid[i];
processid[i]=temp;
temp=arrivaltime[j];
arrivaltime[j]=arrivaltime[i];
arrivaltime[i]=temp;
temp=brusttime[j];
brusttime[j]=brusttime[i];
brusttime[i]=temp;
}
}
}
 
for(j=0;j<n;j++)
{
btime=btime+brusttime[j];
min=brusttime[k];
for(i=k;i<n;i++)
{
if (btime>=arrivaltime[i] && brusttime[i]<min)
{
temp=processid[k];
processid[k]=processid[i];
processid[i]=temp;
temp=arrivaltime[k];
arrivaltime[k]=arrivaltime[i];
arrivaltime[i]=temp;
temp=brusttime[k];
brusttime[k]=brusttime[i];
brusttime[i]=temp;
}
}
k++;
}
waitingtime[0]=0;
for(i=1;i<n;i++)
{
sum=sum+brusttime[i-1];
waitingtime[i]=sum-arrivaltime[i];
wsum=wsum+waitingtime[i];
}
 
waitingavg=(wsum/n);
for(i=0;i<n;i++)
{
turnaroundtime=turnaroundtime+brusttime[i];
totaltime[i]=turnaroundtime-arrivaltime[i];
tsum=tsum+totaltime[i];
}
 
turnaroundavg=(tsum/n);
system("cls");
 
printf("********");
printf("\n RESULT:-");

for(i=0;i<n;i++)
{
	printf("\nSequence of process execution is:-%d",processid[i]);
}
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",processid[i],brusttime[i],arrivaltime[i],waitingtime[i],totaltime[i]);
}
printf("\n\nAVERAGE WAITING TIME : %f",waitingavg);
printf("\nAVERAGE TURN AROUND TIME : %f",turnaroundavg);
return 0;
}
