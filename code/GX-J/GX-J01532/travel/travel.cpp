#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string s1,s2;
   int c1,c2;
   cin>>c1>>s1>>c2>>s2;
   if(c1==c2)cout<<"1";
   else{
   cout<<"0000"; return 0;}
   int a=0;
   for(int i=0;i<=6;i++){
   if(s1+i==s2||s1==s2+i)a=1;}
   if(a==1)cout<<"1";
   else{
   cout<<"000";
   return 0;}
   for(int w=0;w<=18;w++){
   if(s1-w=='D'&&s2-w=='c'||s1-w=='C'&&s2-w=='D')a=2;}
   if(a==2)cout<<"1";
   else{ cout<<"00";
   return 0;
   }
   for(int e=0;e<=18;e++){
   if(s1-('A'+e+1)==s2-('A'+e)||s1-('A'+e)==s2-('A'+e+1))a=5;
   }
   if(a==5)cout<<"1";
   else{
   cout<<"0";
   return 0;}
   return 0;}
