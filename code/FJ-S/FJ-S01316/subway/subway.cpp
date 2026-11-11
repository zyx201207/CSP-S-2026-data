#include <bits/stdc++.h>
#define N 505
#define M 500005
#define inf 5000000000000000000ll
using namespace std;

typedef long long ll;

ll c, n, m, q, d, w[M];

long long f[N][N];

vector <pair <ll, ll> > edge[M], reg[N];

int main() {
//	system("fc subway.out subway7.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	for(ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for(ll j = 1; j <= k; j++) {
			ll p, r;
			cin >> p >> r;
			edge[p].push_back(make_pair(i, r));
			reg[i].push_back(make_pair(p, r));
		}
	}
	memset(f, 0x3f, sizeof(f));
	for(ll i = 1; i <= n; i++) f[i][i] = 0;
	for(ll i = 1; i <= n; i++) {
		for(auto u : reg[i]) {
			ll p = u.first;
			for(auto v : edge[p]) {
				ll qs = v.first;
				if(qs == i) continue;
				f[i][qs] = min(f[i][qs], (ll)u.second + v.second);
			}
		}
	}
	for(ll k = 1; k <= n; k++) 
		for(ll i = 1; i <= n; i++) 
			for(ll j = 1; j <= n; j++) 
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q--) {
		ll u, v;
		cin >> u >> v;
		ll ans = inf;
		for(auto x : edge[u]) {
			for(auto y : edge[v]) {
				ans = min(ans, w[u] + w[v] + x.second + y.second + f[x.first][y.first]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}



