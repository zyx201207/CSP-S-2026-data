#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int N = 510;
const int M = 2e4 + 10;
const int M2 = 5e5 + 10;
int c, n, m, d, q, w[N], a[N][M], t[N][M], dis[N][N], dis2[M2], vis[N][M], vis2[N], b[N][N]; vector<int> g[M];
inline void add(int u, int v, int id) { g[u].push_back(v), b[u][v] = id; }
inline void init()
{
	memset(dis, 0x3f, sizeof dis); for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (i == j) continue;
		else
		{
//			for (int k = 1; k <= n; k++) if (vis[k][i] && vis[k][j]) { dis[i][j]  }
		}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	c = 11;
	for (int i = 1; i <= m; i++) cin >> w[i];
	int T;
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++) { cin >> a[i][j] >> t[i][j], T = t[i][j], vis[i][a[i][j]] = 1; if (j > 1) add(a[i][j - 1], a[i][j], i); }
	}
	if (7 <= c <= 11)
	{
		while (q--)
		{
			int x, y; cin >> x >> y;
			memset(dis2, 0x3f, sizeof dis), memset(vis2, 0, sizeof vis2), dis2[x] = 0;
			priority_queue<pii, vector<pii>, greater<pii>> q; q.push({0, 1});
			while (q.size())
			{
				pii hh = q.top(); q.pop(); int u = hh.second;
				if (vis2[u]) continue; vis2[u] = 1;
				for (auto to : g[u])
					if (dis2[to] > dis2[u] + 2 * t[b[u][to]][to]) dis2[to] = dis2[u] + 2 * t[b[u][to]][to], q.push({dis2[to], to});
			}
			cout << w[x] + dis2[y] + w[y] << '\n';
		}
		return 0;
	}
	if (12 <= c <= 19)
	{
		while (q--)
		{
			int x, y;
			cin >> x >> y;
			memset(dis2, 0x3f, sizeof dis2), dis2[x] = 0;
			queue<int> q; q.push(x);
			vector<int> r;
			while (q.size())
			{
				int u = q.front(); q.pop();
				r.push_back(u);
				if (u == y) break;
				for (auto to : g[u]) if (dis2[u] + 1 < dis2[to]) dis2[to] = dis2[u] + 1, q.push(to);
			}
			int ans = 0;
			for (size_t i = 0, las = -1; i < r.size() - 1; i++)
				if (las == -1) las = b[r[i]][r[i + 1]];
				else if (las != b[r[i]][r[i + 1]]) ans += 2 * T, las = b[r[i]][r[i + 1]];
			cout << w[x] + ans + w[y] << '\n';
		}
		return 0;
	}
	init();
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << w[x] + dis[x][y] + w[y] << '\n';
	}
	return 0;
}
