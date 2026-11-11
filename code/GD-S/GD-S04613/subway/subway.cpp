#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
int c,n,m,d,q,k,x,y,tot;
int w[50005],a[505],t[505];
vector<pair<int,int> >e[505];
ll vis[50005],ans[505][505];
void dfs(int u)
{
	if (vis[u]) return;
	vis[u] = 1;
	for (auto [v,dis]:e[u])
	{
		ans[u][v] = ans[v][u] = dis;
		dfs(v);
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		cin >> k;
		for (int j = 1;j <= k;j ++)
		{
			cin >> a[j] >> t[j];
		}
		for (int j = 1;j <= k;j ++)
		{
			for (int s = 1;s <= k;s ++)
			{
				if (j != s) e[a[j]].push_back({a[s],t[j]+t[s]});
				else continue;
			}
		}
	}
	memset(ans,0x3f,sizeof(ans));
	for (int i = 1;i <= m;i ++)
	{
		ans[i][i] = 0;
	}
	dfs(1);
	for (int i = 1;i <= m;i ++)
	{
		for (int j = 1;j <= m;j ++)
		{
			for (int l = 1;l <= m;l ++)
			{
				if (i < j) ans[i][j] = ans[j][i] = min(ans[i][j],ans[i][l] + ans[l][j]);
				else continue;
			}
		 } 
	}
	for (int p = 1;p <= q;p ++)
	{
		cin >> x >> y;
		cout << ans[x][y] + w[x] + w[y] << endl;
	}
	return 0;	
}
