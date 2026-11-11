#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> g[1000005];
int p[1000005];
int nn[1000005];
int ans = 10000005;
int d[1000005];
int vis[1000005];
void dfs1(int x, int _f, int dep)
{
	d[x] = min(d[x], dep);
	for(auto y : g[x])
	{
		if(y != _f)
		{
			dfs1(y, x, dep + 1);
		}
	}
}
void dfs2(int x)
{
	vis[x] = 1;
	for(auto y : g[x])
	{
		if(nn[y] && vis[y] == 0)
		{
			vis[y] = 1;
			dfs2(y);
		}
	}
}
void dfs(int nw, int ii)
{
	if(nw > k)
	{
		int mx = -1;
		for(int i = 1; i <= n; i++)
		{
			d[i] = 10000005;
			vis[i] = 0;
		}
		int ccc = 0;
		for(int i = 1; i <= k; i++)
		{
			if(vis[p[i]] == 0)
			{
				ccc++;
				if(ccc > 2)
				{
					return;
				}
				dfs2(p[i]);
			}
		}
		for(int i = 1; i <= k; i++)
		{
			dfs1(p[i], 0, 0);
		}
		for(int i = 1; i <= n; i++)
		{
			mx = max(mx, d[i]);
		}
		ans = min(ans, mx);
		return;
	}
	for(int i = ii; i <= n; i++)
	{
		p[nw] = i;
		nn[i] = 1;
		dfs(nw + 1, i + 1);
		nn[i] = 0;
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		ans = 10000005;
		cin >> n >> k;
		int u, v;
		for(int i = 1; i <= n; i++)
		{
			g[i].clear();
		}
		for(int i = 1; i < n; i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 1);
		cout << ans << '\n';
	}
	return 0;
}


