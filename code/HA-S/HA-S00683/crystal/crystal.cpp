#include <bits/stdc++.h>
using namespace std;
long long n,m,k,sum=-1,num,l;
long long a[1000001],b[1000001],c[1000001];
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
k=a[i]-a[j];
if(k>=0)
{
b[i]+=k;
}
}
}
for(int i=1;i<=n;i++)
{
if((b[i]>=0)&&(b[i]<=m))
{
for(int j=1;j<=n;j++)
{
c[j]=a[i]-a[j];
}
l=m;
for(int j=n;j>=1;j--)
{
if((c[j]>=0)&&(c[j]<=l))
{
num++;
l=l-c[j];
}
}
sum=max(sum,num);
num=0;
}
}
cout<<sum;
return 0;
}
 
