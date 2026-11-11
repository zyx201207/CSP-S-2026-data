#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

ll C, T, n, d, a[2000005];
int f[5005][5005], g[5005][5005];
int Min[5005];
void sub_1() {
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			f[l][r] = 1e9;
			g[l][r] = 0;
			if (a[r] - a[l] <= d) {
				f[l][r] = 1;
				g[l][r] = 1;
				Min[r] = l;
			}
			for (int k = Min[r]; k <= min(Min[r] + 2, r - 1); k++) {
				if (f[k][r] > 1) break;
				if (f[l][r] == f[l][k] + f[k][r]) {
					g[l][r] += g[l][k] * g[k][r];
				}
				if (f[l][r] > f[l][k] + f[k][r]) {
					f[l][r] = f[l][k] + f[k][r];
					g[l][r] = g[l][k] * g[k][r];
				}
			}
			if (g[l][r] > 2) g[l][r] = 3;
		}
	}
	ll ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l + 1; r <= n; r++) {
			if (g[l][r] == 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
int f_a[2000005], g_a[2000005];
void sub_A() {
	ll ans = 0;
	int Max = 0;
	for (int i = 2; i <= n; i++) {
		f_a[i] = 1e9;
		g_a[i] = 0;
		if (a[i] - a[1] <= d) {
			f_a[i] = 1;
			g_a[i] = 1;
			Max = i;
		}
		for (int j = min(Max, i - 1); j >= max(2, min(Max, i - 1) - 3); j--) {
			if (f_a[j] > 1) break;
			if (f_a[i] == f_a[j] + f_a[i - j + 1]) {
				g_a[i] += g_a[j] * g_a[i - j + 1];
			}
			if (f_a[i] > f_a[j] + f_a[i - j + 1]) {
				f_a[i] = f_a[j] + f_a[i - j + 1];
				g_a[i] = g_a[j] * g_a[i - j + 1];
			}
		}
		if (g_a[i] > 2) g_a[i] = 3;
	}
	for (int i = 2; i <= n; i++) {
		if (g_a[i] == 2) {
			ans += (n - i + 1);
		}
	}
	cout << ans << endl;
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (C <= 10) {
		sub_1();
		return ;
	}
	if (C == 11 || C == 12) {
		sub_A();
		return ;
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

ans = 9

11 1
10 21
0 7 14 21 28 35 42 49 56 63

ans = 5
*/
