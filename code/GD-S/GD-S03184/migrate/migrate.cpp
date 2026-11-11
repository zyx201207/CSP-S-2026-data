#include <bits/stdc++.h>
using namespace std;
int c, t, n, start;
long long d, x[5010], ans[5010][5010], sm[5010][5010];
void dfs(int s, int cnt) {
	if (sm[start][s] > cnt) {
		ans[start][s] = 0;
		sm[start][s] = cnt;
	}
	if (sm[start][s] == cnt) {
		ans[start][s]++;
	}
	for (int i = s + 1; i <= n && x[i] - x[s] <= d; i++) {
		dfs(i, cnt + 1);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		memset(ans, 0, sizeof(ans));
		memset(sm, 0x3f3f3f3f, sizeof(sm));
		for (int i = 1; i <= n; i++) {
			start = i;
			dfs(i, 0);
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (ans[i][j] == 2) {
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
} 
