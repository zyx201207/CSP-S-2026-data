#include <iostream>
#include <vector>

namespace preFile
{
	void init()
	{
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

const int maxn = 1e6 + 3;
const int inf = 0x7f7f7f7f;
int n, k;
std::vector<int> g[maxn];

namespace small
{
	int st[13], fa[13], dep[13], ans;
	bool vis[13];
	
	void clear()
	{
		for (int i = 1; i <= n; i++) st[i] = 0, fa[i] = 0, dep[i] = 0;
		ans = inf;
	}
	
	void dfs(int u)
	{
		vis[u] = true;
		for (int v : g[u]) if (!vis[v] && st[v]) dfs(v);
	}
	
	bool check()
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) vis[i] = false, cnt += st[i];
		if (cnt != k) return false;
		cnt = 0;
		for (int i = 1; i <= n; i++) if (!vis[i] && st[i]) cnt++, dfs(i);
		if (cnt > 2) return false;
		return true;
	}
	
	void dfs1(int u)
	{
		for (int v : g[u])
		{
			if (fa[u] == v) continue;
			fa[v] = u, dep[v] = dep[u] + 1, dfs1(v);
		}
	}
	
	int LCA(int u, int v)
	{
		if (dep[u] < dep[v]) std::swap(u, v);
		while (dep[u] > dep[v]) u = fa[u];
		while (u != v) u = fa[u], v = fa[v];
		return u;
	}
	
	int dis(int u, int v)
	{ return dep[u] + dep[v] - 2 * dep[LCA(u, v)]; }
	
	void calc()
	{
		if (!check()) return;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!st[i])
			{
				int tmp = inf;
				for (int j = 1; j <= n; j++) if (st[j]) tmp = std::min(tmp, dis(i, j));
				res = std::max(res, tmp);
			}
		}
		ans = std::min(ans, res);
	}
	
	void dfsc(int now)
	{
		if (now > n) return calc();
		for (int i = 0; i <= 1; i++)
		{
			st[now] = i;
			dfsc(now + 1);
			st[now] = 0;
		}
	}
	
	void Main()
	{
		clear(), dfs1(1), dfsc(1);
		//for (int i = 1; i <= n; i++) std::cout << fa[i] << ' ' << dep[i] << '\n';
		//st[1] = st[4] = 1;
		//std::cout << dis(1, 3) << '\n';
		//calc();
		std::cout << ans << '\n';
	}
}

void solve(int c)
{
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1, u, v; i < n; i++) std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
	if (c <= 3) return small::Main();
}

int main()
{
	preFile::init();
	int c, t; std::cin >> c >> t;
	while (t--) solve(c);
	return 0;
}
