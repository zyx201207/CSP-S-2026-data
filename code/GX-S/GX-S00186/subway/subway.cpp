#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510, M = 5e5 + 10;
struct Edge{int v, w;};
vector<Edge> e[N + M];
int W[M], dis[N + M];
bool vis[N + M];
priority_queue<int, vector<int>, greater<int> > q;
int c, n, m, d, Q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) cin >> W[i];
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1, x, y; j <= k; j++)
			cin >> x >> y,
			e[x].push_back({m + i, y}),
			e[m + i].push_back({x, y});
	}
	for (int x, y; Q; Q--)
	{
		cin >> x >> y;
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		q.push(x), vis[x] = 1, dis[x] = 0;
		for (int u; q.size();)
		{
			u = q.top(), q.pop();
			for (auto [v, w] : e[u])
			{
				if (dis[u] + w < dis[v])
					dis[v] = min(dis[v], dis[u] + w);
				if (!vis[v]) vis[v] = 1, q.push(v);
			}
		}
		cout << dis[y] + W[x] + W[y] << '\n';
	}
	return 0;
}