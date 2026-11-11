#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
struct walk{
	int a, t;
	bool operator < (const walk &o) const {
		return t > o.t;
	}
};
int w[500005];
vector<walk> G[500505];
bool vis[500505];
int ds[1005][1005];
int djr(int x, int y) {
	memset(vis, 0, sizeof(vis));
	priority_queue<walk> que;
	que.push({x, 0});
	while(que.size()) {
		walk w = que.top();
		que.pop();
		int u = w.a;
		int t = w.t;
		if (u == y) {
			return t;
		}
		for (auto v : G[u]) {
			if (!vis[v.a]) {
				que.push({v.a, t + v.t});
				vis[v.a] = true;
			}
		}
	}
	return -1;
}
int djr_B(int x, int y) {
        memset(vis, 0, sizeof(vis));
        queue<walk> que;
        que.push({x, 0});
        while(que.size()) {
                walk w = que.front();
                que.pop();
                int u = w.a;
                int t = w.t;
                if (u == y) {
                        return t;
                }
                for (auto v : G[u]) {
                        if (!vis[v.a]) {
                                que.push({v.a, t + v.t});
                                vis[v.a] = true;
                        }
                }
        }
        return -1;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(ds, -1, sizeof(ds));
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	// G[1 ~ m]:subway station
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &w[i]);
	}
	//G[m+1 ~ m+n+1]:subway line
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		if (7 <= c && c <= 11) {
			int a1, t1, a2, t2;
			if (k == 1) {
				scanf("%d %d", &a1, &t1);
			} else {
				scanf("%d %d %d %d", &a1, &t1, &a2, &t2);
				G[a1].push_back({a2, t1 + t2});
				G[a2].push_back({a1, t1 + t2});
			}
		} else {
			for (int j = 1; j <= k; ++j) {
				int a, t;
				scanf("%d %d", &a, &t);
				G[m + i].push_back({a, t});
				G[a].push_back({m + i, t});
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (12 <= c && c <= 19) {
			printf("%d\n", w[x] + djr_B(x, y) + w[y]);
		} else {
			printf("%d\n", w[x] + djr(x, y) + w[y]);
		}
	}
}
