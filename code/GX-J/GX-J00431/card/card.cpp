#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m,b,c;
cin>>n>>m;
int a[10005]=0;
for(int i=0;i<=n-1;i++)[
cin>>a[i];}
int d=0;
for(int i=0;i<=n-1;i++){
if(a[i]>a[i+1}){
b=a[i];}
if(a[i]<a[i+1]){
c=a[i]+1;
if(b==a[i+1]){
for(int j=0;j<=i;j++){
pop(j);}}
d+=1;
cout<<3<<d<<1;

return 0;}
