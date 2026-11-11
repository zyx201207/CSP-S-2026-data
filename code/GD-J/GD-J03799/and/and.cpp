#include<bits/stdc++.h> 
using namespace std;
int n,a[200001],b[200001],p,w[200001],y[200001][1000000000],f[200001],d[1000000000],m;
void as(int v,int g){
int o=0;
while(v!=0){
int j=1,u=1;
while(v-j<0){
u++;
j*=2;	
}
v-=j/2;
y[g][u]=1;
o=max(u,o);
}
f[g]=o;
}
int qw(){
fill(d,d+1000000001,1);
for(int i=1;i<=m;i++){
for(int j=1;j<=f[b[i]])
d[j]=y[b[i]][j]&&d[j];
}
int k=1,j=1,x=0;
while(d[f[b[i]]]>=k){
x+=j;
j*=2;
k++;
}
return x;	
}
int zx(int h){
if(h==m){
p=max(p,qw());
}
for(int i=1;i<=n;i++){
if(!w[i]){
w[i]=1;
b[h+1]=a[i];
zx(h+1);
w[i]=0;
}
}		
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
as(a[i],i);
}
zx(0);
cout<<p;
return 0;
}
