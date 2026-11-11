#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int a[N], n, m;
long long f[N][N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		f[i][1] = a[i];
	}
	for (int k = 1; k <= m; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j < n; j ++) {
				f[i][k] = max({f[i][k], f[i][k - 1] & a[i], f[j][k - 1] & a[i]});
			}
		}
	}
	cout << f[n][m];
	return 0;
}
