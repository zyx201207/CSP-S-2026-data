#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		int c=0;
		for(int i=1; i<=n; i++)
		{
			int x;
			cin>>x;
			c=max(c,x);
		}
		cout<<c;
	}
	if(m==2)
	{
		int c=0;
		int a[n];
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				int x=a[i]||a[j];
				c=max(c,x);
			}
		}
		cout<<c;
	}
	if(m==n-1)
	{
		int c=0;
		int a[n];
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		int x=a[1];
		for(int i=2; i<=n; i++)
		{
			for(int j=2; j<=i; j++)
			{
				x=x||a[j];
			}
			for(int j=i+2; j<=n; j++)
			{
				x=x||a[j];
			}
			c=max(c,x);
		}
		cout<<c;
	}
	if(m==n)
	{
		int a[n];
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		int c=a[1];
		for(int i=2; i<=n; i++)
		{
			c=c||a[i];
		}
		cout<<c;
	}
	return 0;
}
