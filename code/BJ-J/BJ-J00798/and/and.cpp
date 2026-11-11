#include<bits/stdc++.h>
using namespace std;
long long dp[200005];
int n,m;
long long a[200005],vis[200005];
int maxn = -1;
void dfs(int k,int f)
{
	if(f == m + 1)
	{
		maxn = max(maxn,k);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(k & a[i],f + 1);
			vis[i] = 0;
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(a[i],1);
	}
	cout << maxn;
	return 0;
}
