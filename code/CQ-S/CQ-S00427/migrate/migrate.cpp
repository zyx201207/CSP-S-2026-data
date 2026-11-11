#include <bits/stdc++.h>

#define int long long

using namespace std;

namespace zcq_qwq {
	const int N = 5000 + 5, inf = 0x3f3f3f3f3f3f3f3f, M = 2e6;
	
	int a[M], d[N][N], cnt[N][N], sum[N];
	
	int t, n, D, c;
	
	void sol1() {
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = inf, cnt[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			deque<int> q;
			int l = i;
			for (int j = 0; j <= n; j++) sum[j] = 0;
			q.push_back(l);
			sum[0] = 1;
			d[l][l] = 0, cnt[l][l] = 1;
			for (int j = i + 1; j <= n; j++) {
				while (!q.empty() && a[j] - a[q.front()] > D) q.pop_front();
				while (l <= j && a[j] - a[l] > D) {
					if (d[i][l] < inf) sum[d[i][l]] -= cnt[i][l];
					l++;
				}
				if (!q.empty()) {
					d[i][j] = d[i][q.front()] + 1;
					cnt[i][j] = sum[d[i][q.front()]];
					if (cnt[i][j] > 2) cnt[i][j] = 3;
					sum[d[i][j]] += cnt[i][j];
					while (!q.empty() && d[i][q.back()] > d[i][j]) q.pop_back();
					q.push_back(j);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (cnt[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	void sol2() {
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (D < (a[2] - a[1]) * 2) {
			cout << 0 << '\n';
			return;
		}
		for (int i = 2; i * 2 - 1 <= n; i++) {
			if (D >= i * (a[2] - a[1]) && D < (i + 1) * (a[2] - a[1])) {
				cout << n - 2 * i + 1 << '\n';
				return;
			}
		}
		cout << 0 << '\n';
	}
	
	void solve() {
		cin >> n >> D;
		if (c <= 10) {
			sol1();
		} else if (c >= 11 && c <= 12) {
			sol2();
		}
	}
	
	void main() {
		cin >> c >> t;
		while (t--) {
			solve();
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	zcq_qwq::main();
	return 0;
}

/*
n ^ 2 做法是单调队列优化 DP。 
*/
