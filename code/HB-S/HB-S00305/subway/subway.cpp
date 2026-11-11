#include<bits/stdc++.h>
using namespace std;
struct lb{
int p;
int z;
}o[37];
bool cmp(lb a,lb b){
return a.z>b.z;
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);

int c=0,n=0,m=0,d=0,q=0;
vector<int> w,k,a[507],t[507],x,y,l[607][37];
int v=0,i=0,j=0,r=0,s=0,h=0,f=0;
cin>>c>>n>>m>>d>>q;
while(v<m){
v++;
cin>>w[v];
}
while(i<n){
i++;
cin>>k[i];
j=0;
while(j<k[i]){
j++;
cin>>a[i][j]>>t[i][j];
}
j=0;
v=1;
while(j<k[i]){
j++;
if(j-1>=1){
l[a[i][j]][v][0]=a[i][j-1];
l[a[i][j]][v][1]=t[i][j]+t[i][j-1];
v++;
}
if(j+1<=k[i]){
l[a[i][j]][v][0]=a[i][j+1];
l[a[i][j]][v][1]=t[i][j]+t[i][j+1];
v++;
}
}
}
while(r<q){
r++;
cin>>x[r]>>y[r];
s=w[x[r]]+w[y[r]];
if(c>=7&&c<=11){
h=x[r];
while(h!=y[r]){
s+=l[h][1][1];
h=l[h][1][0];
}
cout<<s<<"\n";
}else if(c>=12&&c<=19){
int ss=0;
v=0
h=x[r];
while(1){
v++;
if(l[h][v][0]==y[r]){
break;
}else{
if(l[h][v][0]<=0||l[h][v][0]>n){
h=l[h][v-1][0];
v=0;
}
}
}
cout<<s+ss*t[1][1]<<"\n";
}else{
int g[607]={-1};
g[x[r]]=0;
f=1;
h=x[r];
while(m){
v=1;
while(l[h][v][0]>0){
if(l[h][v][1]<g[l[h][v][0]]||g[l[h][v][0]]==-1){
g[l[h][v][0]]=l[h][v][1];
o[f].p=l[h][v][0];
o[f].z=l[h][v][1];
f++;
}
v++;
}
sort(o+1,o+v+1,cmp);
h=o[f].p;
f--;
m--;
}
cout<<s+g[y[r]]<<"\n";
}
}
return 0;
}
