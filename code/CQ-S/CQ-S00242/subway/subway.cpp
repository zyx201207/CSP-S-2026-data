#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], a[505][505], t[505][505];
struct st{
	int date, to, w;
};
vector<st> g[505];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (x + y) * 5 << "\n";
	}
	return 0;
}
