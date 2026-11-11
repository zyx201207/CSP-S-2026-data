#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 2e6 + 3;

int c, t, n, k, u, v;
vector<int> e[maxn];
int dep[maxn], maxdep[maxn], fa[maxn], dis[maxn];
bool vis[maxn];

namespace baoli {
	int bfs(unsigned long long bits) {
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			vis[i] = false;
			dis[i] = 0x3f3f3f3f;
		}
		for(int i = 0; i < 64; i++) {
			if((bits >> i) & 1) {
				q.push(i + 1);
				dis[i] = 0;
			}
		}
		while(q.size()) {
			int u = q.front();
			q.pop();
			if(vis[u]) continue;
			vis[u] = true;
			for(auto v : e[u]) {
				if(dis[u] + 1 < dis[v]) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		int maxx = 0;
		for(int i = 1; i <= n; i++) {
			maxx = max(maxx, dis[i]);
		}
		return maxx;
	}

	int query(int u) {
		if(fa[u] == u) return u;
		return fa[u] = query(fa[u]);
	}

	void unite(int u, int v) {
		int fa1 = query(u);
		int fa2 = query(v);
		fa[fa1] = fa2;
	}

	bool check(unsigned long long bits) {
		for(int i = 1; i <= n; i++) fa[i] = i;
		vector<int> nodes;
		for(int i = 0; i < 64; i++) {
			if((bits >> i) & 1) nodes.push_back(i + 1);
			if(nodes.size() > k) return false;
		}
		if(nodes.size() <= 2) return true;
		int set_cnt = 0;
		for(int i = 1; i < nodes.size(); i++) {
			unite(nodes[0], nodes[i]);
		}
		for(int i = 0; i < nodes.size(); i++) {
			if(fa[nodes[i]] == nodes[i]) set_cnt++;
			if(set_cnt > 2) return false;
		}
		return true;
	}

	int solve() {
		if(n > 64) return -1;
		int ans = 0x3f3f3f3f;
		for(unsigned long long x = 0; (1 << x) < n; x++) {
			if(!check(x)) continue;
			ans = min(ans, bfs(x));
		}
		return ans;
	}
}

namespace k_2 {
	void dfs(int u, int Fa) {
		dep[u] = dep[Fa] + 1;
		fa[u] = Fa;
		maxdep[u] = dep[u];
		for(auto v : e[u]) {
			if(v == Fa) continue;
			dfs(v, u);
			maxdep[u] = max(maxdep[u], maxdep[v]);
		}
	}

	int solve() {
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++) {
			dep[i] = 0;
			dfs(i, 0);
			int cur = 0;
			if(e[i].size() == 1) cur = maxdep[e[i][0]] - 2;
			else {
				int maxx = 0, maxcnt = 0;
				for(auto v : e[i]) {
					if(maxdep[v] > maxx)
						maxx = maxdep[v], maxcnt = 1;
					else if(maxdep[v] == maxx) maxcnt++;
				}
				if(maxcnt > 1) cur = maxx - 1;
				else cur = maxx;
			}
			ans = min(ans, cur);

			for(int j = 1; j <= n; j++) {
				if(dep[j] - dep[i] <= 1) continue;

			}
		}
	}
}

namespace chain {
	int solve() {
		if((n - k) % 4 == 0) return (n - k) / 4;
		return (n - k) / 4 + 1;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1; i < n; i++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(t == 13 || t == 14) {
			cout << chain::solve() << '\n';
		} else if(t == 7 || t == 11 || t == 12) {
			cout << k_2::solve() << '\n';
		} else {
			cout << baoli::solve() << '\n';
		}
	}

	return 0;
}