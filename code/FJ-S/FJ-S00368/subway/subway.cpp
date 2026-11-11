#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647
using namespace std;

inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

const ll N = 5e5 + 5;
vector <pair <ll, ll>> e[N];
ll w[N], f[505][505];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll TESTID = rd(), n = rd(), m = rd(), d = rd(), Q = rd();
	for(ll i = 1; i <= m; i++) w[i] = rd();
	for(ll i = 1; i <= n; i++) {
		ll k = rd();
		while(k--) {
			ll x = rd(), t = rd();
			e[x].push_back(make_pair(i, t));
		}
	}
	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) if(i != j) f[i][j] = 1e18;
	for(ll i = 1; i <= m; i++) {
		for(auto X : e[i]) for(auto Y : e[i]) if(X != Y) {
			ll x = X.first, y = Y.first;
			f[x][y] = f[y][x] = min(f[x][y], X.second + Y.second);
		}
	}
	for(ll k = 1; k <= n; k++) for(ll i = 1; i <= n; i++) 
		for(ll j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(Q--) {
		ll x = rd(), y = rd(), ans = 1e18;
		for(auto X : e[x]) for(auto Y : e[y]) 
			ans = min(ans, w[x] + w[y] + f[X.first][Y.first] + X.second + Y.second);
		cout << ans << '\n';
	}
	return 0;
}
/*

*/


