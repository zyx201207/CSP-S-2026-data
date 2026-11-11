#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int N=2e5+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]==0)
		{
			cout<<0;
			return 0;
		}
	}
	int ans=a[1];
	for(int i=1;i<=n;i++)
	{
		ans&=a[i];
	}
	if(m==1)
	{
		cout<<maxn;
	}
	else if(m==n)
	{
		cout<<ans;
	}
	else if(m==2)
	{
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
	}
	else if(m==n-1)
	{
		int maxx=0;
		int sum;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				sum=a[2];
			}
			else
			{
				sum=a[1];
			}
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				sum&=a[j];
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
	}
	return 0;
}
