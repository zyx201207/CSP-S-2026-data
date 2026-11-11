#include <bits/stdc++.h>
using namespace std;
const long long N = 505, M = 5e5 + 5, K = 5e5 + 5, Q = 1e5 + 5; 
long long c, n, m, d, q;
long long w[M], k[N], a[N][K], t[N][K], x[Q], y[Q];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			scin >> a[i][j] >> t[i][j];
		}
	}	
	for (int r = 1; r <= q; r++) {
		cin >> x[r] >> y[r];
	}
	return 0;
}
