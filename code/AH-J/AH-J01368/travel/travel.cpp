#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>s1>>s2>>c1>>c2;
   if(s1[0]==c1[0]&&s1[1]==c2[1]){
          cout<<1;
   }else{
          cout<<0<<0<<0<<0;
          return 0;
   }
   if(s2[0]==c2[0]&&s2[1]==c2[1]){
          cout<<1;
   }else{
          cout<<0<<0<<0;
          return 0;
   }
   if(s2[2]=='F'&&c2[2]=='D'){
          cout<<11;
   }else if(s2[2]=='D'&&c2[2]=='F'){
          cout<<11;
   }else if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
         if(c2[2]!='C'&&c2[2]!='D'){
               cout<<1;
               if(s2[2]!='B'&&c2[2]!='B')cout<<0;
               else cout<<1;
         }else{
               cout<<0<<0;
         }
   }

   return 0;
}
