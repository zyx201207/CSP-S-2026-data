#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 10;
bool vis[N];
long long x[N];
int f[N], dis[N];

long long get(int x) {
	if (x < 4) return 0LL;
	return 1LL * (x - 3) * (x / 2) / 2;
}

void solve() {
	int n;
	long long d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		memset(dis, 0x3f, sizeof(dis));
		queue<int> q;
		q.push(i);
		dis[i] = 0, f[i] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v = u + 1; v <= n and x[v] - x[u] <= d; v++) {
				if (vis[v]) {
					if (dis[v] == dis[u] + 1) f[v]++;
					continue;
				} vis[v] = 1;
				dis[v] = dis[u] + 1;
				f[v] = 1;
				q.push(v);
			}
		} for (int j = i; j <= n; j++) {
			if (vis[j] and f[i] == 2) ans++;
			//cout << dis[i] << ' ';
		} //cout << '\n';
	} cout << ans << '\n';
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
