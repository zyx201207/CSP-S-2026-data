#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.cpp","r",stdin);
	freopen("string.cpp","w",stdout);
long long n,i=1,l=1,f,j,x,y=0;
cin>>n;
char a[n+1],c[30000];
int b[n+1];
for(;i<=n;i++){
cin>>f>>a[i];
b[i]=f;
}
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)
for(x=1;x<=b[i];x++)
c[x]=a[j];
}
for(i=1;1<=n/2;i++)
if(c[i]!=c[n+1-i])
y++;
cout<<y;
return 0;
}
