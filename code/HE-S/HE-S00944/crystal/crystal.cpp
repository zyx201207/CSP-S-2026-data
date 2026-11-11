#include<bits/stdc++.h>
using namespace std;
int a[500020];
int q,w=1,j,s=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+1+n);
if(n%2==1){
q=a[(n+1)/2];
}
else
q=a[n/2+1];

for(int i=1;i<=n;i++){
if(a[w]<=q){
j=q-a[w];
if(j<=m&&j>=0){
m=m-j;
s++;
}
}
else if(a[w]>q){
j=a[w]-q;
if(j<=m&&j>0){
m=m-j;
s++;
}
}
w++;
}
cout<<s;
fclose(stdin);
fclose(stdout);
return 0;
}
