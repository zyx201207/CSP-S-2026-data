#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (m==1)
	{
		for (int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if (m==n)
	{
		maxx=a[1];
		for (int i=2;i<=n;i++)
		{
			maxx&=a[i];
		}
		cout<<maxx;
		return 0;
	}
	if (m==2)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=m+i;j++)
			{
				int x=j;
				if (x>n)
				{
					x=j-n;
				}
				if (x!=i)
				{
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	else
	{
		cout<<0;	
	}
	return 0;
} 
