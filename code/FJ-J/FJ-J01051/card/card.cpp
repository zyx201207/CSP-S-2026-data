#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[512345],b[312345],c[312345],so[512345];
stack <int> z;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=n;i>=1;i--)
	{
		so[i]=c[a[i]];
		c[a[i]]=i;
	}
	if (n*n<=80000000)
	{
		for (int j=1;j<=n;j++)
		{
			for (int i=1;i<=m;i++)
			{
				c[i]=0;
			}
			for (int i=j;i<=n;i++)
			{
				if (c[a[i]]==0)
				{
					z.push(a[i]);
					c[a[i]]=1;
				}
				else
				{
					while (z.top()!=a[i])
					{
						c[z.top()]=0;
						z.pop();
					}
				}
			}
			while (z.size()>0)
			{
				b[z.top()]+=1;
				z.pop();
			}
		}
	}
	else
	{
		for (int j=1;j<=n;j++)
		{
			for (int i=1;i<=m;i++)
			{
				c[i]=0;
			}
			for (int i=j;i<=n;)
			{
				if (so[i]>0)
				{
					i=so[i];
				}
				else
				{
					b[a[i]]+=1;
					i+=1;
				}
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
