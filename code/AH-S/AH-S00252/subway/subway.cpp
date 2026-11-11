#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
using namespace std;
struct node {
	int x, l;
	bool operator < (const node& a) const {
		if (l != a.l) return l > a.l;
		return x > a.x;
	}
};
struct edge {
	int to, l;
};
vector<vector<edge> > a;
int c, n, m, d, q, cnt;
int w[500010];
void made(int x, int y, int l) {
	a[x].push_back((edge){y, l});
}
void new_node() {
	++cnt;
	a.push_back(vector<edge>());
}
// vector<int> dis;
int dij(int s, int t) {
	priority_queue<node> q;
	vector<int> dis(cnt + 1, 1e9);
	// dis.resize(cnt + 1);
	rep (i, 0, cnt) dis[i] = 1e9;
	vector<bool> vis(cnt + 1, false);
	q.push((node){s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		int x = q.top().x;
		q.pop();
		if (vis[x]) continue;
		if (x == t) return dis[t];
		vis[x] = true;
		for (auto k : a[x]) {
			int y = k.to;
			int l = k.l;
			if (dis[y] > dis[x] + l) {
				dis[y] = dis[x] + l;
				q.push((node){y, dis[y]});
			}
		}
	}
	return dis[t];
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	a.resize(m + 1);
	rep (i, 1, m) scanf("%d", &w[i]);
	cnt = m;
	rep (i, 1, n) {
		int k;
		scanf("%d", &k);
		int lst = 0;
        new_node();
		rep (j, 1, k) {
			int x, l;
			scanf("%d%d", &x, &l);
			made(x, cnt, l);
			made(cnt, x, l);
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", w[x] + dij(x, y) + w[y]);
	}
	return 0;
}
