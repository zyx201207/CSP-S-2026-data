#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int M = 510, N = 5e5 + M;
int c, m, n, d, q, id[N];
long long w[N], t[N], dis[M][M];
vector<pair<int, long long> > e[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway7.in", "r", stdin);
//	freopen("subway7.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
//	cout << "check\n";
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int id; long long t;
			cin >> id >> t;
//			cout << id << ' ' << t << '\n';
			e[m + i].push_back({id, t});
			e[id].push_back({m + i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
//	cout << "1\n";
	for (int i = 1; i <= m; i++)
	{
//		if (e[i].size() > 2) cout << i << ' ' << e[i].size() << '\n';
		for (int j = 0; j < e[i].size(); j++)
		{
			for (int k = j + 1; k < e[i].size(); k++)
			{
				long long u = e[i][j].first - m, v = e[i][k].first - m, w = e[i][j].second + e[i][k].second;
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++) cout << dis[i][j] << ' ';
//		cout << '\n';
//	}
//	cout << "2\n";
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++) cout << dis[i][j] << ' ';
//		cout << '\n';
//	}
	while (q--)
	{
		int u, v; long long ans = 4e18;
		cin >> u >> v;
		for (int i = 0; i < e[u].size(); i++)
		{
			for (int j = 0; j < e[v].size(); j++)
			{
//				cout << e[u][i].second << ' ' << e[v][j].second << '\n';
				ans = min(ans, e[u][i].second + e[v][j].second + dis[e[u][i].first - m][e[v][j].first - m]);
			}
		}
//		cout << ans << '\n';
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}
