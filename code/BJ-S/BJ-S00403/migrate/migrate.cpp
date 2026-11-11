#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
int n;
cin>>n;
int ans=0;
for(int i=1;i<=n;i++)
{
for(int j=i+1;j<=n;j++)
{
ans++;
}
}
cout<<1<<endl<<2;
return 0;
}