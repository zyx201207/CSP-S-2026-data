#include<bits/stdc++.h>
using namespace std;
struct b{
long long c;
string d;
}a[100000];
int main(){
preopen('and.in','r',stdin);
preopen('and.out','w',stdout);
long long n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i].c;
while(a[i].c>0){
a[i].d=a[i].d+a[i].c%2;
a[i].c=a[i].c/2;
}
string g;
int h[10000],o=1;
for(int i=1;i<=n;i++){
if(a[i].d.size()<4){
while(a[i].d.size()<4){
a[i].d='0'+a[i].d;
}
}
}
}
for(int i=1;i<n;i++){
for(int j=i+1;i<=n;j++){
for(int k=1;k<=n;k++){
if(a[i].d[i]=='1'&&a[j].d[i]=='1'){
g=g+'1';
}else{
g=g+'0';
}
}
h[o++]=g[0]-'0'*8+g[1]-'0'*4+g[2]-'0'*2+g[3]-'0'*1;
}
}
int max=0;
for(int i=1;i<=o;i++){
if(h[i]>max){
max=h[i];
}
}
cout<<max;






return 0;
}
