#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e6 + 10; 

int dis[N], cnt[N], ans, c, t, n, d, x[N];
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
			if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.push(v), cnt[v] = 1;
			else if (dis[v] == dis[u] + 1) ++cnt[v];
		}
	}
	for (int i = 1; i <= n; ++i) if (cnt[i] == 2 && i > s) ++ans; 
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	for (cin >> c >> t; t; t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (x[j] - x[i] <= d) g[i].push_back(j), g[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; ++i) bfs(i);
		cout << ans << '\n';
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

