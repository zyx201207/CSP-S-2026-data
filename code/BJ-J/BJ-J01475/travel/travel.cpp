#include<bits/stdc++.h>
using namespace std;

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int main(){
   char a[50];
   for(int i=1;i<=2;i++){
        cin>>a[i];
   }
   for(int i=4;i<=6;i++){
        cin>>a[i];
   }
   for(int i=7;i<=8;i++){
        cin>>a[i];
   }
   for(int i=10;i<=12;i++){
        cin>>a[i];
   }
   if(a[1]==a[7] && a[2]==a[8]) cout<<1;
   else {
         cout<<"0000";
         return 0;
   }
   if(a[4]==a[10] && a[5]==a[11]) cout<<1;
   else{
         cout<<"000";
         return 0;
   }

   if((a[6]-a[12]==1 || a[12]-a[6]==1) && a[6]!='C' && a[6]!='D' || a[12]!='C' && a[12]!='D') cout<<1;
   else if(a[6]=='D' && a[12]=='F' || a[6]=='F' && a[12]=='D') cout<<1;
   else if(a[6]=='C' && a[12]=='A' || a[6]=='A' && a[12]=='C') cout<<1;
   else{
         cout<<"00";
         return 0;
   }

   if(a[6]!='C' && a[6]!='A' || a[12]!='C' && a[12]!='A') cout<<1;
   else cout<<0;


   return 0;
}
