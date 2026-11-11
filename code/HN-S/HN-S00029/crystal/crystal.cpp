#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,d=1000000000000,sum=0;
	cin>>n>>m;
	long long x;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<d&&a[i]>0)
		{
			d=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]<d)
			{
				m-=1;
				a[i]++;
				if(m==0)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	if(d>0)
	{
		for(int i=1;i<=n;i++)
		{
			x+=a[i];
		}
		if(m>=3000)
		{
			x=x/n;	
		}
		else if(m>=10000)
		{
			x=x/n+10;
		}
		else
		{
			x=x/n-1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]<x)
				{
					a[i]++;
					m-=1;
					if(m==0)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==x)
			{
				sum++;
			}
		}
		cout<<sum;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==d)
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
} 
