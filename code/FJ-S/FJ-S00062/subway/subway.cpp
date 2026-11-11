#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 505, M = 5e5 + 5, D = 25;

int n, m, c, d, q, deg[M], ln[M][D];
ll w[M], t[M][D], g[N][N]; 

void solve() {
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			ll x, y; cin >> x >> y;
			++deg[x], ln[x][deg[x]] = i, t[x][deg[x]] = y;
		}
	}
	memset(g, 0x3f, sizeof g);
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= deg[i]; j++) {
			for(int k = j + 1; k <= deg[i]; k++) {
				g[ln[i][j]][ln[i][k]] = min(g[ln[i][j]][ln[i][k]], t[i][j] + t[i][k]), g[ln[i][k]][ln[i][j]] = min(g[ln[i][k]][ln[i][j]], t[i][j] + t[i][k]);
			}
		}
	}
	for(int i = 1; i <= n; i++) g[i][i] = 0;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	while(q--) {
		int x, y; cin >> x >> y;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i <= deg[x]; i++) {
			for(int j = 1; j <= deg[y]; j++) {
				ans = min(ans, w[x] + t[x][i] + g[ln[x][i]][ln[y][j]] + t[y][j] + w[y]);
			}
		} 
		cout << ans << endl;
	}
}
//rp++
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T = 1;
//	cin >> T;
	while(T--) solve();

	return 0;
}

