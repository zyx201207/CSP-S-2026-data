#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("r","and.in",);
freopen("w","and.ans",);
int m,n,mx=0;
cin>>n>>m;
int a[n+10],b[n+10];
for(int i=1;i<=n;i++){
cin>>a[i];
}
int s=0,mi[n+10];
for(int j=1;j<=n;j++){
for(int k=1;k<=n;k++){
if(j!=k){
int g=0,l=0;
int q=a[j],p=a[k];
while(max(q,p)>0){
g+=(q%2&p%2)*pow(2,l);
l++;
q/=2,p/=2;
}
if(g>s){
mi[1]=k,mi[2]=j;s=g;
}
}
}
}
mx=s;
for(int i=1;i<m;i++){
s=0;
for(int k=1;k<=n;k++){
int g=0,l=0;
int q=a[k],p=mx;
while(max(q,p)>0){
g+=(q%2&p%2)*pow(2,l);
l++;
q/=2,p/=2;
}
if(g>s){
int o=0;
for(int u=1;u<=2+i-1;u++){
if(k==mi[u])o++;
}
if(o==0){
s=g;
mi[2+i]=k;
}
}
}mx=s;
}cout<<mx;
return 0; 
}

