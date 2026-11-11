#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int c, n, m, d, q, w[N], k[507][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i][0];
		for (int j = 1; j <= 2 * k[i][0]; j++)
			cin >> k[i][j];
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << x + y << endl;
	}
	return 0;
}
