#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll N = 505;
constexpr ll M = 5e5 + 5;
ll c, n, m, d, q;
ll w[M];
ll dp[N][N];
struct Node{
	ll v, w; 
};
vector <Node> g[M];
void floyd() {
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(dp, 0x3f, sizeof(dp));
	for (ll i = 1; i <= n; i++) dp[i][i] = 0;
	for (ll i = 1; i <= m; i++) cin >> w[i];
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll a, t;
			cin >> a >> t;
			g[a].push_back(Node{i, t});
		}
	}
	for (ll i = 1; i <= m; i++) {
		for (Node j : g[i]) {
			for (Node k : g[i]) {
				if (j.v == k.v) continue;
				dp[j.v][k.v] = j.w + k.w;
			}
		}
	}
	floyd();
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (Node u : g[x]) {
			for (Node v : g[y]) {
				ans = min(ans, dp[u.v][v.v] + u.w + v.w);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
} 
// CCFÈËÌ«ºÃÁË 
