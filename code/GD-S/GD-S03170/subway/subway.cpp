#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<vector<P>> g(m + 1);
	vector<ll> w(m + 1);
	vector<vector<ll>> t(n + 1, vector<ll> (m + 1));
	for(int i = 1; i <= m; i ++)
		cin >> w[i];
	for(int i = 1; i <= n; i ++)
	{
		int k, l;
		cin >> k >> l;
		cin >> t[i][l];
		for(int j = 2; j <= k; j ++)
		{
			int u;
			cin >> u;
			cin >> t[i][u];
			g[l].push_back({u, i});
			g[u].push_back({l, i});
			l = u;
		}
	}
	while(q --)
	{
		int x, y;
		ll et = 1e18;
		cin >> x >> y;//1 3
		auto dfs = [&](auto && s, int u, int fa, int r, ll sum) -> void
		{
			if(u == y)
			{
				et = min(et, sum + t[r][y]);
				return ;
			}
			for(auto [v, w] : g[u])
			{
				if(v == fa)continue;
				if(r == w)s(s, v, u, r, sum);
				else s(s, v, u, w, sum + t[r][u] + t[w][u]);
			}
		};
		int dis = g[x][0].second;
		dfs(dfs, x, 0, dis, t[dis][x]);
		cout << et + w[x] + w[y] << '\n';
	}
} 
