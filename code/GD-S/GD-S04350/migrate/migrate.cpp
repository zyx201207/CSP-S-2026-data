#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10, N1 = 5010;
int a[N], dis[N1][N1], cnt[N1][N1];
vector<int> v[N1];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
//	if (c == 13 || c == 14) {
//		while (t--) {
//			int n, d;
//			cin >> n >> d;
//			for (int i = 1; i <= n; i++) cin >> a[i];
//			for (int i = 1; i <= n; i++) {
//				if (abs(a[1] - a[i]) <= d && abs(a[i] - a[n]) <= d) continue; // 万能点 
//				// 找出所有距离其为2的点 
//				int ll = a[i] - 2 * d, lr = a[i] - d, rl = a[i] + d, rr = a[i] + 2 * d;
//				int posll = lower_bound(a + 1, a + n + 1, ll) - a, poslr = upper_bound(a + 1, a + n + 1, lr) - a - 1;
//				int posrl = lower_bound(a + 1, a + n + 1, rl) - a, posrr = upper_bound(a + 1, a + n + 1, rr) - a - 1;
//				if (posll <= poslr) cnt += 
//			}
//		}
//	}
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++)
				cnt[i][j] = 0;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (abs(a[i] - a[j]) <= d) v[i].push_back(j);
			}
		}
		for (int i = 1; i <= n; i++) {
			queue<int> q;
			q.push(i);
			for (int j = 1; j <= n; j++) dis[i][j] = 0x3f3f3f3f3f3f3f3f;
			dis[i][i] = 0, cnt[i][i] = 1;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto x : v[u]) {
					if (dis[i][u] + 1 < dis[i][x]) {
						dis[i][x] = dis[i][u] + 1;
						cnt[i][x] = cnt[i][u];
						q.push(x);
					} else if (dis[i][u] + 1 == dis[i][x]) cnt[i][x] += cnt[i][u];
				}
			}
		}
		int cnt1 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (cnt[i][j] == 2) cnt1++;
			}
		}
		cout << cnt1 << '\n';
	}
	return 0;
}
