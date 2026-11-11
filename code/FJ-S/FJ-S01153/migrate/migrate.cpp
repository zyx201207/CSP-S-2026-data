#include <iostream>
#include <queue>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define N 200005
#define int long long

int c, q, d, n, a[N];
int dis[N], cnt[N];
void bfs(int u) {
	queue<int> q;
	q.push(u);
	dis[u] = 0;
	cnt[u] = 1;
	while (! q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = t - 1; i >= 1; i --) {
			if (a[t] - a[i] > d) {
				break;
			}
			if (dis[i] == -1) {
				q.push(i);
				dis[i] = dis[t] + 1;
				cnt[i] = cnt[t];
				continue;
			}
			if (dis[t] + 1 > dis[i]) {
				continue;
			}
			if (dis[t] + 1 == dis[i]) {
				cnt[i] += cnt[t];
			}
		}
		for (int i = t + 1; i <= n; i ++) {
			if (a[i] - a[t] > d) {
				break;
			}
			if (dis[i] == -1) {
				q.push(i);
				dis[i] = dis[t] + 1;
				cnt[i] = cnt[t];
				continue;
			}
			if (dis[t] + 1 > dis[i]) {
				continue;
			}
			if (dis[t] + 1 == dis[i]) {
				cnt[i] += cnt[t];
			}
		}
	}
	return;
}

signed main() {
	Write by ___NightDay___;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> q;
	while (q --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[j] = -1;
				cnt[j] = 0;
			}
			bfs(i);
			for (int j = 1; j <= n; j ++) {
				if (cnt[j] == 2) {
					ans ++;
				}
			}
		}
		cout << ans / 2 << endl;
	}
	return 0;
}

// 40pts
