#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
int ans;
int n,m;
void dfs(int x,int sum,int cnt)
{
	if(cnt>m) return;
	if(x==n+1)
	{
		if(cnt==m) ans=max(ans,sum);
		return;
	}
	dfs(x+1,sum,cnt);
	dfs(x+1,sum&a[x],cnt+1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(1,(1ll<<30)-1,0);
		cout<<ans;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1)
	{
		sort(a+1,a+n+1);
		ans=a[2];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else
	{
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=1;i<=m;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
