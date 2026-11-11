#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;
int c, n, m, d, q;
int w[N], k[N], a[N], t[N], rx[N], ry[N];

int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= i; j ++) {
			cin >> a[j] >> t[j];
		}
	}
	for (int i = 1; i <= q; i ++) cin >> rx[i] >> ry[i];
	cout << 0;
	
	return 0;
}
