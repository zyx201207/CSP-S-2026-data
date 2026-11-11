#include<bits/stdc++.h>
using namespace std;
int main(){
int k,t;
cin>>k>>t;
while(t>0){
t--;
int dao,fly;
cin>>dao>>fly;
int a[dao];
int cha =0;
for(int i=0;i<dao;i++){
cin>>a[i];
if(i>1){
cha=a[i]-a[i-1];}

}
cout<<cha;
if(fly<2*cha){
cout<<dao-1<<endl;}
else{
int daodao=0;
for(int i=fly+1;i<dao+1;i++){
daodao+=a[i]-1-fly;
}
cout<<daodao<<endl;
}}
return 0;}
