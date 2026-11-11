#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(m==1)
	{
		long long maxn=0;
		for(int i=0;i<n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n)
	{
		int ans=a[0];
		for(int i=1;i<n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		long long maxn=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else
	{
		sort(a,a+n);
		bool flag=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			{
				flag=0;
			}
		}
		if(flag)
		{
			cout<<a[0];
			return 0;
		}
		int minn=a[0];
		flag=1;
		for(int i=0;i<n;i++)
		{
			int pd=log2(a[i]+1);
			pd=pow(2,pd)-1;
			if(pd!=a[i])
			{
				flag=0;
			}
		}
		if(flag)
		{
			cout<<a[n-m];
			return 0;
		}
		cout<<0;
	}
	return 0;
}
