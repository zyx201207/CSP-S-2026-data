#include<bits/stdc++.h>
using namespace std;
int a[40],b[40];
long long cnt=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int m,n,x,m1=0,m2=0;
cin>>m>>n;
for(int i=1;i<=m;i++){
cin>>x;
if(x>m1){
m2=m1;
m1=x;
}else if(x>m2) m2=x;
}
int i=0;
while(m1!=0){
a[i]=m1%2;
m1/=2;
i++;
}
i=0;
while(m2!=0){
b[i]=m2%2;
m2/=2;
i++;
}
for(int i=1;i<=30;i++){
if(a[i]==1&&b[i]==1) cnt+=pow(2,i);
}
cout<<cnt;
return 0;
}