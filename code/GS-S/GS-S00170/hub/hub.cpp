#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5, mod = 998244353;
struct DSU
{
	vector<int> p, siz;
	DSU(int _n) : p(_n + 1), siz(_n + 1)
	{
		iota(p.begin(), p.end(), 0);
	}	
	int find(int x)
	{
		return x == p[x] ? x : p[x] = find(p[x]);
	}
	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y) return ;
		if (siz[x] > siz[y]) swap(x, y);
		p[x] = y;
		siz[y] += siz[x];
	}
	bool same(int u, int v)
	{
		return find(u) == find(v);
	}
};
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<bool> vis(n + 1);
	int ans = 1e9;
	auto dfs = [&](int pos, int cnt, auto &&dfs) -> void
	{
		if (cnt > k) return ;
		if (pos == n + 1)
		{
			if (cnt < k) return ;
			// 先检查一下连通块个数
			DSU d(n);
			int num = k;
			for (int i = 1; i <= n; i++)
			{
				if (!vis[i]) continue;
				for (auto j : g[i])
				{
					if (!vis[j]) continue;
					if (!d.same(i, j))
					{
						d.merge(i, j);
						num--;
					}
				}
			} 
			if (num > 2) return ;
			queue<int> q;
			vector<int> dis(n + 1, -1);
			for (int i = 1; i <= n; i++) if (vis[i]) dis[i] = 0, q.push(i);
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int v : g[u])
				{
					if (dis[v] == -1)
					{
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			int res = *max_element(dis.begin(), dis.end());
			ans = min(ans, res);
			return ;
		}
		vis[pos] = 1;
		dfs(pos + 1, cnt + 1, dfs);
		vis[pos] = 0;
		dfs(pos + 1, cnt, dfs);
	};
	dfs(1, 0, dfs);
	cout << ans << "\n"; 
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
