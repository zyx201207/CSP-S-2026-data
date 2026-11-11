#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,sum=0,c=0;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
for(int j=1;j<=n;j++)
{
	sum=sum+a[j];
	for(int x=0;x<=m;x++)
	{
	if((sum+x)/j==a[j+1])
	{
		c=j;
	}
	}
}
cout<<c+1;
return 0;
}
