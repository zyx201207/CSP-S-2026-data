#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
const int N = 2000010;
int C, T;
int n, D, ans, a[N], dis[5010][5010];
void solve() {
	ans = 0;
	cin >> n >> D;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	bool blB = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[1] <= D && a[n] - a[i] <= D) blB = 1;
	}
	if (blB && n > 5000) {
		cout << 0 << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = 1e9;
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (abs(a[i] - a[j]) <= D) dis[i][j] = 1;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int cc = 0;
			for (int k = i + 1; k < j; k++) {
				if (dis[i][j] != dis[i][k] + dis[k][j]) continue;
				for (int p = k + 1; p < j; p++) {
					if (dis[i][j] != dis[i][p] + dis[p][j]) continue;
					if (dis[i][j] != dis[i][k] + dis[k][p] + dis[j][p]) cc++;
				}
			}
			if (cc == 1) ans++;
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		solve();
	}
	return 0;
}
