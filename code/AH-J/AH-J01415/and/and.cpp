#include<bits/stdc++.h>
using namespace std;
int ai(int x,int y)
{
return x&y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int i,j,n,m,max2,flag[100010]={0};
long long a[100001],max1=0;
cin>>n>>m;
for(i=1;i<=n;i++)
{
cin>>a[i];
}
for(i=1;i<n;i++)
{
for(j=i+1;j<=n;j++)
if(ai(a[i],a[j])>=max2)
{
max2=ai(a[i],a[j]);
}
}
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
if(ai(a[i],a[j])==max2)
{
flag[i]=1;
flag[j]=1;
}
while(m-2>0)
{
max1=-1;
for(i=1;i<=n;i++)
if(ai(max2,a[i])>=max1&&flag[i]==0)
{
max1=ai(max2,a[i]);
flag[i]=1;
}else continue;
max2=max1;
m--;
}
cout<<max2<<endl;
return 0;
}
