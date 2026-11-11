#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const ll INF = 1e18;
// bool __st__;
int c, n, m, d, q;
ll w[M];
vector<pair<int, ll>> to[M];
ll dis[N][N];
// bool __ed__;
// void PrintMem() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
signed main()
{
	// PrintMem();
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k, a, t;
		cin >> k;
		while (k--)
		{
			cin >> a >> t;
			to[a].push_back({i, t});
		}
		for (int j = 1; j <= n; j++)
			dis[i][j] = INF;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
		for (pair<int, ll> sbcpp14_1 : to[i])
			for (pair<int, ll> sbcpp14_2 : to[i])
				dis[sbcpp14_1.first][sbcpp14_2.first] = min(dis[sbcpp14_1.first][sbcpp14_2.first], sbcpp14_1.second + sbcpp14_2.second);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1, u, v; i <= q; i++)
	{
		cin >> u >> v;
		ll ans = INF;
		for (pair<int, ll> sbcpp14_1 : to[u])
			for (pair<int, ll> sbcpp14_2 : to[v])
				ans = min(ans, dis[sbcpp14_1.first][sbcpp14_2.first] + sbcpp14_1.second + sbcpp14_2.second);
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
} // 15: 00