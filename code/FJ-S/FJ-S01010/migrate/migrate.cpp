#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 2e6 + 10;
int c, T;
int n, d;
int x[N];
int cnt[5010][5010];
void solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	if (c == 11 || c == 12) {
		int f = x[2] - x[1];
		int ans = n - (d / f) - (d / f - 1);
		if (d <= f || ans < 0) {
			cout << 0 << endl;
			return;
		} 
		cout << ans << endl;
		return;
	}
	if (c == 13 || c == 14) {
		cout << 0 << endl;
		return;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cnt[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			for (int k = i; k <= j; k++) {
				if (x[k] - x[i] <= d && x[j] - x[k] <= d) cnt[i][j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++) {
//			cout << i << " " << j << " " << cnt[i][j] << endl;
			if (cnt[i][j] == 2) ans++;
		} 
	}
	cout << ans << endl;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while (T--) solve();
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') Cf = -1;
	} 
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Ca * Cf;
}