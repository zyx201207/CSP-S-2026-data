#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6;

int testcase, test, n, k, u[N], v[N];
vector<int> edge[N + 1];
int fa[N + 1];
int front, rear, que[N + 1], dist[N + 1];

int get_fa(int node) {
	if (fa[node] == node)
		return node;
	else
		return fa[node] = get_fa(fa[node]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> testcase >> test;
	while (test--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			edge[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
			edge[u[i]].push_back(v[i]);
			edge[v[i]].push_back(u[i]);
		}
		int ans = n;
		for (int i = 1; i < 1 << n; i++) {
			if (__builtin_popcount(i) != k)
				continue;
			for (int j = 1; j <= n; j++)
				fa[j] = j;
			for (int j = 1; j < n; j++) {
				int x = u[j], y = v[j];
				if (get_fa(x) == get_fa(y))
					continue;
				if (i >> x - 1 & 1 && i >> y - 1 & 1)
					fa[get_fa(x)] = get_fa(y);
			}
			pair<int, int> pr = make_pair(-1, -1);
			bool flag = true;
			for (int j = 1; j <= n; j++)
				if (i >> j - 1 & 1) {
					int now = get_fa(j);
					if (pr.first == -1)
						pr.first = now;
					else if (pr.second == -1)
						pr.second = now;
					else
						flag &= now == pr.first || now == pr.second;
				}
			if (flag) {
				front = 1;
				rear = 0;
				for (int j = 1; j <= n; j++)
					dist[j] = -1;
				for (int j = 1; j <= n; j++)
					if (i >> j - 1 & 1) {
						que[++rear] = j;
						dist[j] = 0;
					}
				while (front <= rear) {
					int node = que[front++];
					for (int j : edge[node])
						if (dist[j] == -1) {
							dist[j] = dist[node] + 1;
							que[++rear] = j;
						}
				}
				int mx = 0;
				for (int i = 1; i <= n; i++)
					mx = max(mx, dist[i]);
				ans = min(ans, mx);
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
