#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, d, mn, cnt, x[2000005];
set <int> G[2000005];
void solve() {
	cin >> n >> d;
	if (d == 1) {
		for (int i = 1; i <= n; i++) cin >> x[i];
		cout << "0\n";
		return ;
	}
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (i != 1 && x[i] - x[i - 1] <= d) G[i - 1].insert(i);
		for (int j = i - 2; j > 0; j--)
			if (x[i] - x[j] <= d) G[j].insert(i);
			else break;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = i + 2; j <= n; j++) {
			if (G[i].find(j) != G[i].end()) break;
			int cnt = 0;
			for (int k = i; k <= j; k++) 
				if ((G[i].find(k) != G[i].end()) ^ (G[k].find(j) != G[k].end())) cnt++;
			if (cnt == 2) ans++;
		}
	cout << ans << "\n";
}
void solve2() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int a = x[2] - x[1];
	cout << (d < a * 2 ? 0 : max(n - d / a * 2 + 1, 0ll)) << "\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	if (c == 11 || c == 12) while (T--) solve2();
	else while (T--) solve();
	return 0;
}
