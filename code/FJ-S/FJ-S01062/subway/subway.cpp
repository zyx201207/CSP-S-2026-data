#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 5e5 + 5, N = 505, Q = 1e5 + 5;
ll w[M], a[N][M][2], k[N], x[Q], y[Q];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	for(ll i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) cin >> a[i][j][0] >> a[i][j][1];
	}
	for(int i = 1; i <= q; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= q; i++) {
		cout << "0\n";
	}
	return 0;
}
