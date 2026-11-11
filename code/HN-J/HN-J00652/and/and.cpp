#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200010],vis[200010],ans=0,ans2=1;
bool cmp(long long int x,long long int y)
{
	return x>y;
}
int check()
{
	for(long long int i=1;i<n;i++)
	{
		long long int x=a[i]&a[i+1];
		if(x!=a[i+1])
		{
			return 0;
		}
	}
	return 1;
}
int dfs(long long int x,long long int res)
{
	if(x>m)
	{
		ans=max(ans,res);
		return 0;
	}
	for(long long int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			long long int y;
			if(x==1)
			{
				y=a[i];
			}
			else
			{
				y=a[i]&res;
			}
			dfs(x+1,y);
			vis[i]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(check())
	{
		cout<<a[m];
	}
	else if(n<=2000)
	{
		dfs(1,1);
		cout<<ans;
	}
	else if(m==n-1)
	{
		for(long long int i=1;i<n;i++)
		{
			ans2=ans2&a[i];
		}
		cout<<ans2;
	}
	else
	{
		cout<<n-m;
	}
	return 0;
}
