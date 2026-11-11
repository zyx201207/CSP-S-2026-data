#include<bits/stdc++.h>
using namespace std;

int a[200010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		int maxx=-1e9;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			maxx=max(a,maxx);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(m==2)
	{
		int maxx=-1e9;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int t=a[i]&a[j];
				maxx=max(maxx,t);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n-1)
	{
		int sum=0;
		int maxx=-1e9;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sum=a[2];
		for(int i=3;i<=n;i++)
		{
			sum=sum&a[i];
		}
		maxx=max(maxx,sum);
		for(int i=2;i<=n;i++)
		{
			sum=a[1];
			for(int j=2;j<=n;j++)
			{
				if(j!=i)
				{
					sum=sum&a[j];
				}
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}

