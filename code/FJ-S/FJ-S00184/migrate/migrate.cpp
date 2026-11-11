#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 10;
const int INF = 2e18;
int Tid, T, n, d;
int a[N];
int f[N][N], g[N][N];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		f[i][i] = g[i][i] = 0;
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = 0, g[i][j] = INF;
			if (a[j] - a[i] <= d) g[i][j] = f[i][j] = 1;
		}
	}
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		for (int l = 1; l < n; l++) {
			for (int r = l + 1; r <= n; r++) {
				if (g[l][r] > g[l][k] + g[k][r]) {
					g[l][r] = g[l][k] + g[k][r];
					f[l][r] = f[l][k] * f[k][r];
				}
				else if (g[l][r] == g[l][k] + g[k][r])
					f[l][r] += f[l][k] * f[k][r];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += (f[i][j] == 2);
	cout << ans << '\n';
}
signed main() {
//	system("fc migrate.out migrate3.ans");
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> Tid >> T; while (T--) solve();
}
/*
0 1
4 1
1 2 3 4

0
*/
