
include <bits/stdc++.h>
using namespace std;
int main()
{
   preopen(travel.in,"r",stdin);
   preopen(travel.out,"w",stdout);
   string R1,R2,X1,X2;
   cin>>R1>>R2>>X1>>x2;
   if(R1==X1)
   {
     cout<<"1";
   }
   if(R2/100==X2/100&&R1==X1)
   {
     cout<<"1";
   }

   if((R2%100-X2%100==1||x2%100-R2%100==1)&&(R1==X1)&&(R2/100==X2/100))
   {
     cout<<"1";
   }
   return 0;
}
