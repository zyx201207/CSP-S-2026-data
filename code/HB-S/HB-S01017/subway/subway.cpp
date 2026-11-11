#include<bits/stdc++.h>
using namespace std;
int main(){
int c,road,sta,maxx,plan;
cin>>c>>road>>sta>>maxx>>plan;
int a[sta];
for(int i=0;i<sta;i++){
cin>>a[i];}
int k1;
cin>>k1;
int roa[sta][road]={0};
for(int i=0;i<k1;i++){
int num;
cin>>num;
cin>>roa[num][0];}
int k2;
cin>>k2;
for(int i=0;i<k2;i++){
int num;
cin>>num;
cin>>roa[num][1];}
while(plan>0){
plan--;
int head,tail;
cin>>head>>tail;
int time;
time=a[head-1]+a[tail-1];
int flag=1;
int same=0;
for(int i=0;i<2;i++){
if(roa[head][i]!=0&&roa[tail][i]!=0){
flag=0;
same=i;}}
if(flag==0){
time+=roa[head][same]+roa[tail][same];}
else{
int minn=8888888;
for(int i=head;i<=tail;i++){
if(roa[i][1]!=0&&roa[i][0]!=0){
int ti=roa[i][1]+roa[i][0];
minn=min(minn,ti);
}
}
time+=minn+roa[head][0]+roa[tail][0]+roa[head][1]+roa[tail][1];
}
cout<<time<<endl;
}
return 0;}
