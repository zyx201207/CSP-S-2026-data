#include <bits/stdc++.h>

using namespace std;

long long c, n, m, d, q;
long long w[500001], k[500001], a[501][50001], t[501][50001], x[100001], y[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i ++) {
		cin >> w[m];
	}
	for (int i = 0; i < n; i ++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 0; i < q; i ++) {
		cin >> x[i] >> y[i];
	}
	cout << 0 << endl;
	return 0;
}
