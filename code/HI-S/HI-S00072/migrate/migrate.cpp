#include <bits/stdc++.h>
using namespace std;

int c, t, n, d;
const int maxn = 2e6 + 6;
long long dp[maxn][maxn];
int len[maxn];

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {int w, cnt;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> len[i];
			w = len[i] - len[i - 1];
		}
		if (w > d) {cout << 0 << '\n'; continue;}
		else{
			cnt = d / w;
		}
		dp[1][1] = 1;
		for (int num = 1; num <= n; num++) {
			for (int j = 1; j <= cnt; j++)
				if (num + j <= n) dp[num][num + j]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dp[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
