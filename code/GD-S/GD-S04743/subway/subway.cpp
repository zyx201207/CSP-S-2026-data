#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, n, m, d, q, x, y, sum = 0;
ll w[500005], k, a, t, dis[500505];
vector <pair <int, ll> > e[500505];
bool vis[500505];
void dijkstra(int x)
{
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[x] = 0;
	for (int i = 1; i <= sum; i++)
	{
		ll cnt = 0x7f7f7f7f7f7f7f7f, u = 0;
		for (int j = 1; j <= m; j++)
		{
			if (!vis[j] && dis[j] < cnt)
				u = j, cnt = dis[j];
		}
		vis[u] = 1;
		for (auto v : e[u])
		{
			if (dis[v.first] > dis[u] + v.second)
				dis[v.first] = dis[u] + v.second;
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x7f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		sum += k;
		for (int j = 1; j <= k; j++)
		{
			cin >> a >> t;
			e[a].push_back({m + i, t});
			e[m + i].push_back({a, t});
		}
	}
	m += n;
	while (q--)
	{
		cin >> x >> y;
		dijkstra(x);
		cout << w[x] + w[y] + dis[y] << "\n";
	}
	return 0;
}
