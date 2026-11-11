#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

const int N = 1e6 + 7;

int n, k;
vector<int> to[N];
int fl[N];
vector<pair<int, int> > edge;
int cutu, cutv, dep[N], dis[N];
vector<int> stk;

void dfs1(int u, int fa, int &rt, int &mid) {
	stk.push_back(u);
	if (rt == 0 || dep[rt] < dep[u]) {
		rt = u;
		mid = stk[((int) stk.size() - 1) / 2]; 
	}
	for (int v : to[u]) {
		if (v == fa) continue;
		if ((u == cutu && v == cutv) || (u == cutv && v == cutu)) continue;
		dep[v] = dep[u] + 1;
		dfs1(v, u, rt, mid);
	}
	stk.pop_back();
}

void dfs2(int u, int fa) {
	for (int v : to[u]) {
		if (v == fa) continue;
		if ((u == cutu && v == cutv) || (u == cutv && v == cutu)) continue;
		dfs2(v, u);
		dis[u] = max(dis[u], dis[v] + 1);
	}
	fl[dis[u]] ++;
}

mt19937 rnd(time(0));

void solve() {
	n = read(), k = read(); edge.clear();
	for (int i = 1; i <= n; i ++) to[i].clear();
	for (int i = 1, u, v; i < n; i ++) {
		u = read(), v = read();
		to[u].push_back(v);
		to[v].push_back(u);
		edge.push_back({u, v});
	}
	if (n > 4000) {
		int ans = 2e9;
		shuffle(edge.begin(), edge.end(), rnd);
		for (int _ = 0; _ * n < 40000000 && _ < (int) edge.size(); _ ++) {
			cutu = edge[_].first, cutv = edge[_].second;
			for (int i = 0; i <= n; i ++)
				fl[i] = dep[i] = dis[i] = 0;
			int rt1 = 0, mid1, rt2 = 0, mid2;
			dfs1(cutu, 0, rt1, mid1);
			dfs1(rt1, 0, rt1, mid1);
			dfs2(mid1, 0);
			dfs1(cutv, 0, rt2, mid2);
			dfs1(rt2, 0, rt2, mid2);
			dfs2(mid2, 0);
	//		printf("cut (%d, %d), (%d, %d)\n", cutu, cutv, mid1, mid2);
			for (int i = n - 1; i >= 0; i --)
				fl[i] += fl[i + 1];
			for (int i = 0; i <= n; i ++) {
				if (fl[i] <= k) {
					ans = min(ans, i);
					break;
				}
			}
		}
		cout << ans << '\n';
	} else {
		int ans = 2e9;
		for (auto e : edge) {
			cutu = e.first, cutv = e.second;
			for (int i = 0; i <= n; i ++)
				fl[i] = dep[i] = dis[i] = 0;
			int rt1 = 0, mid1, rt2 = 0, mid2;
			dfs1(cutu, 0, rt1, mid1);
			dfs1(rt1, 0, rt1, mid1);
			dfs2(mid1, 0);
			dfs1(cutv, 0, rt2, mid2);
			dfs1(rt2, 0, rt2, mid2);
			dfs2(mid2, 0);
	//		printf("cut (%d, %d), (%d, %d)\n", cutu, cutv, mid1, mid2);
			for (int i = n - 1; i >= 0; i --)
				fl[i] += fl[i + 1];
			for (int i = 0; i <= n; i ++) {
				if (fl[i] <= k) {
					ans = min(ans, i);
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int qwq = 1, col;
	col = read(), qwq = read();
	while (qwq --)
		solve();
	return 0;
}

