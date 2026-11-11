#include<bits/stdc++.h>
using namespace std;
/*
RE 32
O(n^3 + dq^2)
*/
#define N 305
#define int long long
int c, t, n, d, a[2000005], f[N][N][2];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++) cin >> a[i];
			if (n == 1) {
				cout << "0\n";
				continue;
			}
			int k = a[2] - a[1];
			if (d < 2 * k) {
				cout << "0\n";
				continue;
			}
			d /= k;
			d = d + d - 1;
			cout << max(n - d, 0ll) << "\n";
		}
		return 0;
	}
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				f[i][j][0] = 2 * n;
				f[i][j][1] = 0;
			}
		for (int i = 1; i <= n; i++) {
			f[i][i][0] = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (abs(a[i] - a[j]) <= d) f[i][j][0] = f[i][j][1] = 1;
			}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					if (k == i || k == j) continue;
					if (f[i][k][0] + f[j][k][0] < f[i][j][0]) {
						f[i][j][0] = f[i][k][0] + f[j][k][0];
						f[i][j][1] = f[i][k][1] * f[j][k][1];
//					cout << i << " " << j << " " << k << " " << f[i][j][1] << "\n";
					}
					else if (f[i][k][0] + f[j][k][0] == f[i][j][0]) {
						f[i][j][1] += f[i][k][1] * f[j][k][1];
					}
				}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (f[i][j][1] == 2) {
					ans++;
				}
			}
		cout << ans << "\n";
	}
	return 0;
}
