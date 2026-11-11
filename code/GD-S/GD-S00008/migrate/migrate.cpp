#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e6 + 5;
typedef long long LL;
typedef pair<int,int> PII;
int n;
LL d, a[N];
int dis[N];
LL cnt[N];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dis[j] = 0x3fffffff;
			cnt[j] = 1;
		}
		dis[i] = 0, cnt[i] = 1;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int j = u + 1; j <= n && a[j] - a[u] <= d; j++) {
				if (dis[j] > dis[u] + 1) {
					dis[j] = dis[u] + 1;
					cnt[j] = cnt[u];
					q.push(j);
				} else if (dis[j] == dis[u] + 1) {
					cnt[j] += cnt[u];
				}
			}
		}
		for (int j = i + 1; j <= n; j++) {
			if (cnt[j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		dis[i] = cnt[i] = 0;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
