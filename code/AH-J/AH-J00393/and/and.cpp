#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m,b,c,Max=-10000;
cin>>n>>m;
int a[200005];
for(int i=1;i<=n;i++)
cin>>a[i];
if(m==1)cout<<n;
if(m==2){
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
if(Max<(a[i]&a[j])){
Max=(a[i]&a[j]);
int p=a[i]&a[j];
cout<<p<<endl;
}
cout<<Max;
}}}
if(m==n){
for(int i=2;i<=n;i++){
b=a[i]&a[i-1];
}
cout<<b;
}
return 0;
}
