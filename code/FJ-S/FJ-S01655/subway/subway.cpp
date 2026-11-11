#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 510, M = 500010;
int c, n, m, d, q;
ll w[N];
vector<pair<int, ll> > G[M];
ll f[N][N]; // iºÅÏßµ½ jºÅÏß 

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	    
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while(k--) {
			int a, t;
			cin >> a >> t;
			G[a].emplace_back(i, t);
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			f[i][j] = 1000000000000000;
		}
	}
	for(int i = 1; i <= n; ++i) f[i][i] = 0;
	
	for(int i = 1; i <= m; ++i) {
		for(auto x : G[i]) {
			for(auto y : G[i]) {
				if(f[x.first][y.first] > x.second + y.second) {
					f[x.first][y.first] = x.second + y.second;
					f[y.first][x.first] = x.second + y.second;
				}
			}
		}
	}
	
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while(q--) {
		int a, b;
		cin >> a >> b;
		ll ans = 1000000000000000;
		for(auto x : G[a]) {
			for(auto y : G[b]) {
				ans = min(ans, f[x.first][y.first] + x.second + y.second);
			}
		}
		cout << ans + w[a] + w[b] << "\n";
	}
	return 0;
}

