#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int C, T, n, k, d[N];
vector<int> g[N];
bool vis[N];
queue<int> q;
void DFS(int u, int S)
{
	vis[u] = true;
	for (int v: g[u])
	{
		if (vis[v] || !(S & 1 << v - 1)) continue;
		DFS(v, S);
	}
}
int sz[N], dfn[N], dep[N], dfc;
void DFS2(int u, int pa)
{
	sz[u] = 1;
	dfn[u] = ++dfc;
	dep[u] = dep[pa] + 1;
	for (int v: g[u])
	{
		if (v == pa) continue;
		DFS2(v, u);
		sz[u] += sz[v];
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1, u, v; i < n; i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 0x3f3f3f3f;
		for (int S = 0; S < 1 << n; S++)
		{
			if (__builtin_popcount(S) != k) continue;
			memset(vis + 1, false, sizeof (bool) * n);
			int cnt = 0;
			for (int i = 1; i <= n; i++)
				if (S & 1 << i - 1 && !vis[i])
				{
					DFS(i, S);
					cnt++;
				}
			if (cnt > 2) continue;
			memset(d + 1, -1, sizeof (int) * n);
			for (int i = 1; i <= n; i++)
				if (S & 1 << i - 1)
					q.push(i), d[i] = 0;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int v: g[u])
					if (d[v] == -1)
						q.push(v), d[v] = d[u] + 1;
			}
			ans = min(ans, *max_element(d + 1, d + n + 1));
		}
		cout << ans << endl;
	}
	return 0;
}
