#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 500 + 5;
const int MAXM = 5e5 + 5;
const int MAXD = 25;
typedef long long ll;
int c, n, m, d, q;
ll w[MAXM], k[MAXN];
//int a[MAXN][MAXD];
vector<pair<int, ll> > g[MAXN + MAXM];
//int t[MAXN][MAXD];
ll dij[MAXN + MAXM];
//int vis[MAXN + MAXM];
//int ans[MAXN][MAXN];
void bfs(int x)
{
	for (int i = 1; i <= n + m; i++)
	{
		dij[i] = 0x7fffffff;
//		vis[i] = 0;
	}
	dij[x] = 0;
//	vis[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
//		vis[u] = 1;
		for (auto ed : g[u])
		{
			int v = ed.first;
//			if (vis[v])
//				continue;
			ll w = ed.second;
			if (dij[u] + w < dij[v])
			{
				q.push(v);
				dij[v] = dij[u] + w;
			}
		}
//		vis[u] = 0;
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int a;
			ll t;
			cin >> a >> t;
//			cin >> a[i][j] >> t[i][j];
//			g[m + i].push_back({a[i][j], t[i][j]});
//			g[a[i][j]].push_back({m + i, t[i][j]});
			g[m + i].push_back({a, t});
			g[a].push_back({m + i, t});
		}
	}
//	for (int i = 1; i <= m; i++)
//	{
//		bfs(i);
//		for (int j = 1; j <= m; j++)
//		{
//			ans[i][j] = dij[j];
//			cout << ans[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		bfs(x);
		cout << w[x] + w[y] + dij[y] << '\n';
	}
	return 0;
}
