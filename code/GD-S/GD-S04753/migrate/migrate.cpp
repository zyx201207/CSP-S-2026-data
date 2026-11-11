#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, M = 5000 + 5;
int a[N], dis[M], cnt[M];
vector<int> g[M];
queue<int> q;
void bfs(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v: g[u]) 
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v: g[u])
			if (dis[u] + 1 == dis[v]) {
				cnt[v]++;
				q.push(v);
			}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d, ans;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (c > 10) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++)
				if (a[i] + d >= a[j]) g[i].push_back(j);
				else break;
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			bfs(i);
			for (int j = i + 1; j <= n; j++)
				if (cnt[j] == 2) ans++;
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++) g[i].clear();
		memset(a, 0, sizeof a);
	}
}
