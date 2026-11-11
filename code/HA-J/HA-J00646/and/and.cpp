#include<bits/stdc++.h>
using namespace std;
long long a[200005];long long n,m;
long long maxx1=-999;
long long dfs(long long t,long long maxx,long long x)
{
	if(t==n+1)
	{
		if(x!=m)
		{
			return 0;
		}
		else
		{
			maxx1=max(maxx1,maxx);
			return 0;
		}
	}
	dfs(t+1,maxx,x);
	dfs(t+1,maxx&a[t+1],x+1);
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long sss=-1,ans3;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sss=max(sss,a[i]);
		if(i==1) ans3=a[i];
		else ans3&=a[i];
	}
	if(n<=20)
	{
		for(long long i=1;i<=n;i++)
		{
			dfs(0,a[i],0);
		}
		cout<<maxx1;
		return 0;
	}
	else if(m==1)
	{
		cout<<sss;
		return 0;
	}
	else if(m==2)
	{
		long long amax=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				amax=max(amax,a[i]&a[j]);
			}
		}
		cout<<amax;
		return 0;
	}
	else if(m==n)
	{
		cout<<ans3;
		return 0;
	}
	else 
	{
		int aans;
		sort(a+1,a+n+1);
		aans=a[n];
		for(int i=n-1;i>=n-m;i--)
		{
			aans&=a[i];
		}
		cout<<aans;
	}
	return 0;
}