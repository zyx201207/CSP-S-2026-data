#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back

constexpr ll N = 500, M = 5e5;

ll www[N + M + 10];
ll k[N + M + 10];
ll dis[N + 10][N + 10];
bool vis[N + 10][N + 10];
vector<pll> g[N + M + 10];
vector<pll> adj[N + 10];
ll c, n, m, d, qqq;

struct node
{
	ll id, dis;
	bool operator < (const node &cmp)const
	{
		return dis > cmp.dis;
	}
};

void dij(ll s)
{
	for (ll i = 1; i <= n; i++)
	{
		dis[s][i] = INF;
		vis[s][i] = 0;
	}
	dis[s][s] = 0;
	priority_queue<node> q;
	q.push({s, 0});
	while (!q.empty())
	{
		ll u = q.top().id;
		q.pop();
		if (vis[s][u])
		{
			continue;
		}
		vis[s][u] = 1;
		for (pll p : adj[u])
		{
			ll v = p.first, w = p.second;
			if (dis[s][v] > dis[s][u] + w)
			{
				dis[s][v] = dis[s][u] + w;
				q.push({v, dis[s][v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> qqq;
	for (ll i = 1; i <= m; i++)
	{
		cin >> www[i];
	}
	for (ll i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (ll j = 1; j <= k[i]; j++)
		{
			ll u = m + i, v, w;
			cin >> v >> w;
			g[u].pb({v, w});
			g[v].pb({u, w});
		}
	}
//	for (ll i = 1; i <= m; i++)
//	{
//		for (pll p : g[i])
//		{
//			cout << i << "->" << p.first << " " << p.second << endl;
//		}
//	}
	for (ll u = 1; u <= m; u++)
	{
		for (pll p1 : g[u])
		{
			for (pll p2 : g[u])
			{
				ll v1 = p1.first - m, w1 = p1.second;
				ll v2 = p2.first - m, w2 = p2.second;
				if (v1 == v2)
				{
					continue;
				}
				adj[v1].pb({v2, w1 + w2});
				adj[v2].pb({v1, w1 + w2});
			}
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		dij(i);
	}
	while (qqq--)
	{
		ll l, r;
		cin >> l >> r;
		ll ans = INF;
		for (pll p1 : g[l])
		{
			for (pll p2 : g[r])
			{
				ll v1 = p1.first, v2 = p2.first;
				ll w1 = p1.second, w2 = p2.second;
				ans = min(ans, www[l] + w1 + dis[v1 - m][v2 - m] + w2 + www[r]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

// 16:05 想到思路
// 16:19:27 敲完
// 16:23:55 调完
// 16:25:09 测完全部大样例，应该过了吧
