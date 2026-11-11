#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],s[200005],t,maxn;
void dfs(int x)
{
	if(t==m)
	{
		int ans=s[1];
		for(int i=2;i<=t;i++)
		{
			ans&=s[i];
		}
		maxn=max(maxn,ans);
		return ;
	}
	if(x>n)
	{
		return ;
	}
	dfs(x+1);
	t++;
	s[t]=a[x];
	dfs(x+1);
	t--;
	return ;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		maxn=a[1];
		for(int i=2;i<=n;i++)
		{
			maxn&=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1)
	{
		int s=a[1];
		for(int i=2;i<=n;i++)
		{
			s&=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,s&(-a[i]-1));
		}
		cout<<maxn;
		return 0;
	}
	dfs(1);
	cout<<maxn;
	return 0;
}


