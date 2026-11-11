#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int C, T, n;
long long x[N];
long long a[N][N], b[N][N], c[N];
long long d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		if (n <= 5e3) {
			for (int i = 1; i <= n; ++i) {
				cin >> x[i];
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					a[i][j] = 0;
					b[i][j] = 0;
				}
			}
			for (int i = n; i >= 1; --i) {
				c[i] = n;
				for (int j = i + 1; j <= n; ++j) {
					if (x[j] - x[i] <= d) {
						a[i][j] = 1;
						b[i][j] = 1;
					}
					else {
						c[i] = j - 1;
						break;
					}
				}
			}
			for (int i = n - 1; i >= 1; --i) {
				if (c[i] == i) continue;
				for (int j = i + 1; j <= n; ++j) {
					if (a[i][j] == 1) continue;
					if (a[c[i]][j] != 0) {
						a[i][j] = a[c[i]][j] + 1;
						int l = i + 1, r = c[i];
						while (l < r) {
							int mid = (l + r) >> 1;
							if (a[mid][j] == a[c[i]][j]) r = mid;
							else l = mid + 1;
						}
						b[i][j] = 0;
						for (int k = l; k <= c[i]; ++k) {
							b[i][j] += b[k][j];
							if (b[i][j] > 2) break;
						}
					}
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				//cout << c[i] << '\n';
				for (int j = i + 1; j <= n; ++j) {
					ans += (a[i][j] != 0 && b[i][j] == 2);
					//cout << a[i][j] << ' ';
				}
				//cout << '\n';
			}
			cout << ans << '\n';
			for (int i = n + 1; i >= 1; --i) {
				for (int j = 1; j <= n + 1; ++j) {
					a[i][j] = 0;
					b[i][j] = 0;
					c[i] = 0;
				}
			}
		}
		else {
			for (int i = 1, y; i <= n; ++i) {
				cin >> y;
			}
		}
	}
	return 0;
}
