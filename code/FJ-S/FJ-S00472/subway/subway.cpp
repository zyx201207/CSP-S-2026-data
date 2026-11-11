#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define FILE(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
const int N = 5e2 + 10;
const int M = 1e3 + 10;
struct node{
	int to, w;
};
int tid, n, m, d, q;
int w[M], a[N][M], t[N][M], dis[M][M], w1[M];
vector<node> G[M];
void bfs(int x) {
	queue<node> q;
	q.push((node){x, -1});
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (node it : G[now.to]) {
			if (dis[x][it.to] > dis[x][now.to] + (now.w != it.w) * (t[now.w][now.to] + t[it.w][now.to])) {
				dis[x][it.to] = dis[x][now.to] + (now.w != it.w) * (t[now.w][now.to] + t[it.w][now.to]);
				w1[it.to] = t[it.w][it.to];
				q.push(it);
			}
		}
	}
}
int main() {
	IOS; FILE("subway");
	cin >> tid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		a[i][0] = t[i][0] = k;
		for (int j = 1, tmp; j <= k; j++) {
			cin >> a[i][j] >> tmp;
			t[i][a[i][j]] = tmp;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i][0]; j++) {
			for (int k = 1; k <= a[i][0]; k++) {
				G[a[i][j]].push_back({a[i][k], i});
				G[a[i][k]].push_back({a[i][j], i});
			}
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		dis[i][i] = 0;
		bfs(i);
		for (int j = 1; j <= m; j++) {
			dis[i][j] += w1[j] + w[i] + w[j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] << "\n";
	}
	return 0;
}
