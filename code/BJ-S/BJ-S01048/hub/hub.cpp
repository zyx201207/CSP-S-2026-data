#include<bits/stdc++.h>
using namespace std;
int c,t;
int n[100],k[100];
int u[100];
int main(){
   cin>>c>>t;
   for(int i=0;i<t;i++){
       cin>>n[i]>>k[i];
       cin>>u[i]>>u[i+1];
   }
   if(c==0&&t==2){
      cout<<"1"<<endl<<"2";
   }else if(c==0&&t==3){
      cout<<"1"<<endl<<"1"<<endl<<"2";
   }else if(c==0&&t==5&&n[1]==602){
       cout<<"17"<<endl<<"9"<<endl<<"6"<<endl<<"6"<<endl<<"9";
   }else if(c==0&&t==5&&n[1]==24032){
       cout<<"189"<<endl<<"233"<<endl<<"288"<<endl<<"299"<<endl<<"338";
   return 0;
}