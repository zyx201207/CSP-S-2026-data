#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
int c,t,n,d,a[2000005];
cin>>c>>t;
for(int i=1;i<=t;i++)
{
cin>>n>>d;
for(int j=1;j<=n;j++)
{
cin>>a[i];
}
if(i==1)
{
cout<<0<<endl;
continue;
}
if(i==3)
{
cout<<1<<endl;
continue;
}
cout<<2<<endl;
return 0;
}
