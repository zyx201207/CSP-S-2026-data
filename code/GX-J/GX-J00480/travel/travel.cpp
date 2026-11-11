#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   char c1[2],c2[2],z1[3],z2[3];
   for(int i=0;i<2;i++) cin>>c1[i];
   for(int i=0;i<3;i++) cin>>z1[i];
   for(int i=0;i<2;i++) cin>>c2[i];
   for(int i=0;i<3;i++) cin>>z2[i];
   if(c1[0]==c2[0]&&c1[1]==c2[1]){
   cout<<'1';
   if(z1[0]==z2[0]&&z1[1]==z2[1]){
   cout<<'1';
   if(z1[2]<='c'&&z2[2]<='c'||z1[2]>'c'&&z2[2]>'c'){
   cout<<'1';
   if(char(z1[2]+1)==z2[2]||char(z2[2]+1)==z1[2]||char(z1[2]-1)==z2[2]||char(z2[2]-1)==z1[2]){
   cout<<'1';
   }
   else cout<<'0';
   }
   else cout<<"00";
   }
   else cout<<"000";
   }
   else cout<<"0000";
   return 0;
}
