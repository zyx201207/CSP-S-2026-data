#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5;
int c, n, m, d, qq, w[M], k, a[N][M], t[N][M], dis[M], x, y;
bool book[N];
struct node {
	int v, w;
	bool operator < (const node other) const {
		return w > other.w;
	}
};
vector <node> mapp[M];
priority_queue <node> q;

void dij(int s, int y) {
	memset(book, 0, sizeof book);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	while (q.size()) q.pop();
	q.push(node{s, 0});
	while (q.size()) {
		int k = q.top().v;
		q.pop();
		if (k == y) {
			cout << dis[y] + w[x] + w[y] << "\n";
			return;
		}
		if (book[k]) continue;
		book[k] = 1;
		for (int i = 0; i < mapp[k].size(); i++) {
			int v = mapp[k][i].v, w = mapp[k][i].w;
			if (book[v]) continue;
			if (dis[k] + w < dis[v]) {
				dis[v] = dis[k] + w;
				q.push(node{v, dis[v]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			for (int l = 1; l < j; l++) {
				int u = a[i][l], v = a[i][j], t_1 = t[i][l], t_2 = t[i][j];
				mapp[u].push_back(node{v, t_1 + t_2});
				mapp[v].push_back(node{u, t_1 + t_2});
			}
		}
	}
	while (qq--) {
		cin >> x >> y;
		dij(x, y);
	}
	return 0;
}

