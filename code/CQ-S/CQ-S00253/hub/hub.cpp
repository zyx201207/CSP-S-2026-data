#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e5 + 5;
int c, t;
vector<int> graph[N];
int dist[N];
int fa[N], depth[N];
void dfs1(int u, int father)
{
//	cout << "#\n";
	fa[u] = father;
	depth[u] = depth[father] + 1;
	for (auto v : graph[u])
	{
		if (v == father) continue;
		dfs1(v, u);
	}
}
int length(int u, int v)
{
	int len = 0;
	if (depth[u] < depth[v]) swap(u, v);
	while (depth[u] != depth[v]) u = fa[u], len++;
	while (u != v) u = fa[u], v = fa[v], len += 2;
	return len;
}
bool check(int mask)
{
	vector<int> points;
	int cc = 0;
	for (int i = 0; i < 10; i++)
	{
		if (mask & (1 << i))
		{
			if (cc == 0)
			{
				cc++;
				points.push_back(i + 1);
			}
			else
			{
				bool in = 0;
				for (auto u : points)
				{
					for (auto v : graph[u])
					{
						if (i + 1 == v) in = 1;
					}
				}
				if (!in) cc++;
				points.push_back(i + 1);
			}
			if (cc > 2) return 0;
		}
	}
	return 1;
}
int ans = 1e9;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	memset(dist, 0x3f, sizeof dist);
	cin >> c >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		if (n == k)
		{
			cout << "0\n";
			continue;
		} 
		for (int i = 1; i <= n; i++) graph[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
				
		dfs1(1, 0);
		for (int mask = 0; mask < (1 << 10); mask++)
		{
//			cout << "#\n";
			int res = 0;
			int tot = 0;
			for (int i = 0; i < 10; i++) if (mask & (1 << i)) tot++;
			if (tot != k) continue;
			if (check(mask))
			{
				int res = 0;
				for (int i = 0; i < 10; i++) if (mask & (1 << i))
				{
					int sub = 1e9;
					for (int j = 1; j <= n; j++)
					{
						sub = min(sub, length(j, i + 1));
//						cout << sub << " ";
					}
					res = max(sub, res);
//					cout << res << " ";
				}
				ans = min(res, ans);
			}
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i++) graph[i].clear(), dist[i] = 1e9, fa[i] = 0, depth[i] = 0, ans = 1e9;
	}

	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
