#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],s,ans[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
	for(int i=1;i<=n;i++)
	{
		a[i]=0;
		if(b[i]!=a[i])
		{
			b[i]=1;
		}
		if(b[i]==1)
		{
			for(int j=0;j<n;j++)
			{
				if(j==b[i])
				{
					s=i;
				}
			}
			for(int k=s;k<=i;k++)
			{
				b[k]=0;
			}
		}
		}
	for(int i=n;i<=n;i++)
	{
		if(b[i]==1)
		{
			ans[i]++;
		}
	}
}
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i];
		}
	return 0;
}
