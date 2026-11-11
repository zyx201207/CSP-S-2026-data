#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e6 + 10, M = 5e3 + 10;
int t, n, cnt[M][M];
long long x[N], d, dis[M][M];
vector <int> g[N];

void bfs(int s) {
	queue <int> q;
	q.push(s);
	for (int i = 1; i <= n; i ++) dis[s][i] = 1e9, cnt[s][i] = 0;
	dis[s][s] = 0;
	cnt[s][s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (dis[s][u] + 1 < dis[s][v]) {
				q.push(v);
				dis[s][v] = dis[s][u] + 1;
				cnt[s][v] = cnt[s][u];
			} else if (dis[s][u] + 1 == dis[s][v]) {
				cnt[s][v] += cnt[s][u];
			}
		}
	}
}

void planA() {
	for (int i = 1; i <= n; i ++) g[i].clear();
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (x[j] - x[i] <= d)
				g[i].push_back(j);
			else
				break;
	
	for (int i = 1; i <= n; i ++)
		bfs(i);
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (cnt[i][j] == 2)
				ans ++;
	cout << ans << '\n';
}

void planB() {
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int pos1 = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
		int pos2 = upper_bound(x + 1, x + n + 1, x[pos1] + d) - x - 1;
		int pos3 = upper_bound(x + 1, x + n + 1, x[pos1 - 1] + d) - x - 1;
		if (pos2 > pos1 and pos3 > pos1) ans += pos2 - pos2 + 1;
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		
		if (n <= 5000) planA();
		else planB();
	}
	
	return 0;
}
