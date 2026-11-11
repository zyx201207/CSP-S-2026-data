// 从某条线路到某条线路，V_AB = V_A + V_B 

#include <bits/stdc++.h>
using namespace std;

int c, n, m, o, T;
const int N = 510, M = 5e5 + 10, D = 23, Q = 1e5 + 10;

struct dot {
	int real, val;
};

struct node {
	int from, real, val;
	friend bool operator < (node a, node b) {
		return a.val < b.val;
	}
	friend bool operator > (node a, node b) {
		return a.val > b.val;
	}
};

int d[N][D];
vector<dot> g[2*M+N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	cin >> c >> n >> m >> o >> T;

	//BFS！从0站到11站，利用站线的有限性！！！ 
	
	for (int i = 1; i <= m; i++) {
		int w;
		cin >> w;
		g[0].push_back({i, w});
		g[i+m].push_back({2 * m + 1, w});
		g[i+m].push_back({i, 0});
	}
	
	for (int i = 1; i <= n; i++) {
		int idx = 2 * m + 1 + i, k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[a].push_back({idx, t});
			g[idx].push_back({a+m, t});
		}
	}
	
	priority_queue<node, vector<node>, greater<node>> q;
	for (int i = 1; i <= n; i++) {
		q.push({2 * m + 1 + i, 0, 0});
	}
	
	while(q.size()) {
		node idx = q.top(); q.pop();
		for (auto p : g[idx.real]) {
			if (idx.from == p.real) continue;
			if (d[idx.from][p.real] == 0x3f3f3f3f3f3f3f3f) {
				q.push({idx.from, p.real, idx.val + p.val});
				d[idx.from][p.real] = idx.val + p.val;
			}
		}
	}
	
	for (int i = 1; i <= T; i++) {
		long long x, y, ans = 1e18;
		cin >> x >> y;
		for (auto p : g[x]) {
			ans = min(ans, (long long)g[0][x].val + d[p.real][y] + g[y][2*m+1].val);
		}
		cout << ans << endl;
	}
	
	return 0;
}
