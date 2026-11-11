#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e6 + 5;

int c, t, n, k, dis[N], ans;
vector<int> g[N];

void bfs(int s)
{
	memset(dis, 0x3f, sizeof dis);
	queue<int> q; q.push(s);
	dis[s] = 0;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : g[u])
		{
			if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) ans = max(ans, dis[i]);
}

bool check(int x)
{
	ans = 0;
	for (int i = 1; i <= n; ++i) bfs(i);
	return ans <= x;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	for (cin >> c >> t; t; t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1, u, v; i < n; ++i)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int l = -1, r = n;
		while (l + 1 < r)
		{
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid;
		}
		cout << r << '\n';
	}
	return 0;
}

