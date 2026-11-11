#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5000005],c[5000005],maxn=1;
int dp[5005][5005];
void dfs(int x,int sum,int g,int e)
{
	if (e<0) return;
//	cout << sum <<endl;
	if (sum<=m) maxn=max(maxn,g);
	dfs(x,a[x]-a[e]+sum,g+1,e-1);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if (a[2]-a[1]==1&&a[3]-a[2]==1)
	{
		if (n>5000)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if (ans<=m) maxn=i;
				ans+=i;
			} 
			cout <<maxn;
			return 0;
		}
	}
	if (a[2]-a[1]==a[3]-a[2])
	{
		if (n>5000)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if (ans<=m) maxn=i;
				ans+=i*(a[2]-a[1]);
			}
			cout <<maxn;
			return 0;
		}
	}
	for (int i=2;i<=n;i++)
	{
		dfs(i,0,1,i-1);
	}
	cout << maxn;
	return 0;
}
