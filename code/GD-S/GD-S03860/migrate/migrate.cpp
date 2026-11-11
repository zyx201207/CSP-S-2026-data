#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
long long x[N];

long long n, d;
long long dp[N][N];
long long cnt[N][N];
//void dfs(int beg, int end) {
//	cout << beg << " " << end << "\n"; 
//	if (dp[beg][end] != 0x3f3f3f3f3f3f3f3f) return; 
//	if (x[end] - x[beg] <= d) {
//		dp[beg][end] = 1;
//		cnt[beg][end] = 1;
//		for (int i = beg + 1; i < end; i++) {
//			dp[beg][i] = 1;
//			cnt[beg][i] = 1;
//			dp[i][end] = 1;
//			cnt[i][end] = 1;
//		}
//		return;
//	}
//	for (int i = beg + 1; i < end; i++) {
//		dfs(beg, i);
//		dfs(i, end);
//		if (dp[beg][end] == dp[beg][i] + dp[i][end]) {
////			cout << "多算的cnt" << beg << " " << end << " " << i << "\n"; 
//			cnt[beg][end]++;
//		} else if (dp[beg][end] > dp[beg][i] + dp[i][end]) {
//			dp[beg][end] = dp[beg][i] + dp[i][end];
//			cnt[beg][end] = 1;
//		}
//	} 
//}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i <= n - len; i++) {
				int beg = i, end = i + len;
				if (x[end] - x[beg] <= d) {
					dp[beg][end] = 1;
					cnt[beg][end] = 1;
					continue;
				} 
				for (int j = beg + 1; j < end; j++) {
					if (dp[beg][end] == dp[beg][j] + dp[j][end]) {
//						cout << "多算的cnt" << beg << " " << end << " " << j << "\n"; 
						cnt[beg][end]++;
					} else if (dp[beg][end] > dp[beg][j] + dp[j][end]) {
						dp[beg][end] = dp[beg][j] + dp[j][end];
						cnt[beg][end] = 1;
					}
				} 
			}
		}
//		dfs(1, n);
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (cnt[i][j] == 2) ret++;
//				cout << i << " " << j << " " << dp[i][j] << " " << cnt[i][j] << "\n";
			}
		}
		cout << ret << "\n";
	} 
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
