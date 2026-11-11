#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const ll inf = 1e18;
ll C, n, m, D, q, w[N], d[505][505];
vector <pair<int, int>> s[N], e[N];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
void add(int u, int v, int w)
{
	e[u].emplace_back(v, w);
	e[v].emplace_back(u, w);
}
void dij(int s)
{
	for (int i = 1; i <= n; i++)
		d[s][i] = inf;
	d[s][s] = 0;
	que.emplace(0, s);
	while (!que.empty())
	{
		auto [dd, u] = que.top();
		que.pop();
		if (dd > d[s][u])
			continue;
		for (auto [v, w] : e[u])
		{
			if (d[s][v] > d[s][u] + w)
			{
				d[s][v] = d[s][u] + w;
				que.emplace(d[s][v], v);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1, a, t; j <= k; j++)
		{
			cin >> a >> t;
			s[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = inf;
	for (int i = 1; i <= m; i++)
		for (auto [u1, w1] : s[i])
			for (auto [u2, w2] : s[i])
				if (u1 != u2)
					d[u1][u2] = min(d[u1][u2], 1ll * w1 + w2);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (d[i][j] != inf)
				add(i, j, d[i][j]);
	for (int i = 1; i <= n; i++)
		dij(i);
	while (q--)
	{
		ll u, v, ans = inf;
		cin >> u >> v;
		for (auto [u1, w1] : s[u])
			for (auto [u2, w2] : s[v])
				ans = min(ans, d[u1][u2] + w1 + w2);
		cout << ans + w[u] + w[v] << endl;
	}
	return 0;
}