#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10, MAXM = 5e2 + 10;
vector <pair <int, ll>> g[MAXN], r[MAXN];
vector <pair <int, int>> idx[MAXN];
ll n, m, d, q, w[MAXN], outw[MAXN];
ll f[MAXM][MAXM];
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int c; cin >> c;
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) cin >> w[i];
	
	for (int j = 1; j <= n; ++ j) {
		int t; cin >> t;
		for (int i = 1, u, tim; i <= t; ++ i) {
			cin >> u >> tim;
			r[j].push_back ({u, tim});
			idx[u].push_back ({j, i - 1});
		}
	}
	
	memset (f, 0x3f, sizeof f);
	for (int i = 1; i <= m; ++ i) {
		vector <pair <int, ll>> ve;
		for (auto v : idx[i]) {
			int t = v.first, ix = v.second;
			ll uw = r[t][ix].second;
			for (pair <int, ll> u : ve) {
				int e = u.first;
				ll we = u.second;
				ll tots = uw + we;
				f[t][e] = f[e][t] = tots;
			}
			ve.push_back ({t, uw});
		}
	}
	for (int i = 1; i <= n; ++ i) f[i][i] = 0LL;
	for (int k = 1; k <= n; ++ k) {
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				f[i][j] = min (f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q --) {
		int x, y; cin >> x >> y;
		ll res = LLONG_MAX;
		for (pair <int, int> i : idx[x]) {
			for (pair <int, int> j : idx[y]) {
				int ti = i.first, ixi = i.second;
				int tj = j.first, ixj = j.second;
				res = min (res, w[x] + r[ti][ixi].second + f[ti][tj] + r[tj][ixj].second + w[y]);
			}
		}
		cout << res << "\n";
	}
	return 0;
}
