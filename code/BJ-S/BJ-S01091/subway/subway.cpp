#include<bits/stdc++.h>
using namespace std;
#define int long long
int W[500005];
struct node
{
	int v, w;
};
int ans[100005];
vector<node> G[500505], vec[500005];
int c, n, m, d, q;
int g[505][505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> W[i];
	for(int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		int u = m + i, v, w;
		for(int j = 1; j <= k; j ++)
		{
			cin >> v >> w;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
	}
	for(int i = 1; i <= q; i ++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back({v, i});
	}
	memset(ans, 0x3f, sizeof(ans));
	memset(g, 0x3f, sizeof(g));
	for(int i = 1; i <= n; i ++)
	{
		g[i][i] = 0;
		for(auto u : G[m + i])
		{
			for(auto j : G[u.v])
			{
				if(i == j.v - m) continue;
				g[i][j.v - m] = min(g[i][j.v - m], u.w + j.w);
				g[j.v - m][i] = min(g[j.v - m][i], u.w + j.w);
			}
		}
	}
	for(int k = 1; k <= n; k ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			if(i == k) continue;
			for(int j = 1; j <= n; j ++)
			{
				if(j == k) continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for(int i = m + 1; i <= m + n; i ++)
	{
		for(auto u : G[i])
		{
			for(auto v : vec[u.v])
			{
				for(auto j : G[v.v])
				{
					ans[v.w] = min(ans[v.w], W[u.v] + u.w + g[i - m][j.v - m] + j.w + W[v.v]);
				}
			}
		}
	}
	for(int i = 1; i <= q; i ++) cout << ans[i] << endl;
	return 0;
}
