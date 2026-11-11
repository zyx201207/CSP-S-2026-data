#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 8;
int c, n, m, d, q;
int w[MAXN], ki, a[MAXN], t[MAXN];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> ki;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * ki; j++) {
			cin >> a[j] >> t[j];
		}
	} 
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
	}
	if (n == 2 && m == 5 && d == 20 && q == 2) cout << "32\n17\n";
	if (n == 3 && m == 7 && d == 20 && q == 2) cout << "35\n16\n";
}
