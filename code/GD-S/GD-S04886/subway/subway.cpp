#include <bits/stdc++.h>
using namespace std;
int a[30][30], w[500010], t[500010], qq[100010][4], f[910][910];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int m, c, n, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j += 2) {
			cin >> a[i][j] >> t[i];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> qq[i][1] >> qq[i][2];
		cout << w[qq[i][1]] + w[qq[i][2]];
	}
	return 0;
} 
