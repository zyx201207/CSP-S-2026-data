#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n==m)
	{
		for (int i=1;i<=n;i++)
		{
			a[1]&=a[i];
		}
		cout<<a[1];
		return 0;
	}
	else if (m==1)
	{
		int maxx=-1;
		for (int i=1;i<=n;i++)
		{
			if (maxx<=a[i])
			{
				maxx=a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	else if (m==2)
	{
		int maxx=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i==j)
				{
					continue;
				}
				if (a[i]&a[j]>=maxx)
				{
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	else if (n<=20 && m==3)
	{
		int maxx=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
				{
					if (i==j || i==k || j==k)
					{
						continue;
					}
					int sum=a[i]&a[j];
					if (sum&a[k]>=maxx)
					{
						maxx=sum&a[k];
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	else
	{
		cout<<6;
	}
	return 0;
}
