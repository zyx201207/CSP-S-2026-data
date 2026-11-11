#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back

const int N = 505, M = 5e5 + 5;
const ll inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;

int subid, n, m, d, q;
//      颜色数、口个数 
ll w[M];
vector<pll> v[M];

ll dist[N][N];
inline void chkmin(ll &x, ll y) {
	if (x > y)
		x = y;
}

void slv() {
	cin >> subid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll id, t;
			cin >> id >> t;
			v[id].eb(i, t);
		}
	}
	for (int i = 1; i <= m; i++)
		assert((int)v[i].size() <= d);
	memset(dist, INF, sizeof dist);
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < v[i].size(); j++)
			for (int k = j + 1; k < v[i].size(); k++) {
				chkmin(dist[v[i][j].fi][v[i][k].fi], v[i][j].se + v[i][k].se);
				chkmin(dist[v[i][k].fi][v[i][j].fi], v[i][j].se + v[i][k].se);
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				chkmin(dist[i][j], dist[i][k] + dist[k][j]);
	
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cerr << "? " << i << ' ' << j << ": " << dist[i][j] << '\n';
	
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		
		for (int j = 0; j < v[x].size(); j++)
			for (int k = 0; k < v[y].size(); k++)
				ans = min(ans, dist[v[x][j].fi][v[y][k].fi] + v[x][j].se + v[y][k].se);
		
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
}

int main() {
//	freopen("subway7.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--)
		slv();
//	cerr << "time use: " << 1. * clock() / CLOCKS_PER_SEC << "s" << '\n'; 
	return 0;
}
