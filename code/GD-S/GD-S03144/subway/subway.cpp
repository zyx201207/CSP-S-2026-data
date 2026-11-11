#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin);
#define fou(x) freopen(x, "w", stdout);
#define fre(x) fin(x".in") fou(x".out")
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nit int
#define nti int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
const ll INF = 1e18;
const int M = 5e5 + 5; 
const int N = 5e2 + 5;
vector<pair<ll, ll>>sub[M];
vector<ll>adj[N];
int main() {
	fre("subway")
	ios
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	(void)c;
	vector<ll>w(m + 1);
	For(i, 1, m) cin >> w[i];
	For(i, 1, n) {
		int k;
		cin >> k;
		For(j, 1, k) {
			int u, v;
			cin >> u >> v;
			sub[u].push_back({i, v});
		}
	}
	vector<vector<ll>>dis(n + 1, vector<ll>(n + 1, INF));
	For(i, 1, n) dis[i][i] = 0;
	For(i, 1, m) if ((int)sub[i].size() > 1) {
		For(u, 0, sub[i].size() - 1) For(v, 0, sub[i].size() - 1) {
			if (u == v) continue;
			ll u1 = sub[i][u].first, w1 = sub[i][u].second;
			ll u2 = sub[i][v].first, w2 = sub[i][v].second;
			dis[u1][u2] = min(dis[u1][u2], w1 + w2);
			dis[u2][u1] = dis[u1][u2];
		}
	}
	For(k, 1, n) For(i, 1, n) For(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll ans = INF;
		for (auto i : sub[x]) for (auto j : sub[y]) {
			ll u = i.first, v = j.first;
			ans = min(ans, dis[u][v] + w[x] + w[y] + i.second + j.second);
		}
		cout << ans << '\n';
	}
}
