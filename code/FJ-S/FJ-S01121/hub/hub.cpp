#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 20;
int c, T, n, k;
int f[N][N], vis[N], in[N]; 
vector<int> G[N];

void dp(int u, int st, int fa) {
	for (auto v : G[u]) if (v != fa)
		f[st][v] = f[st][u] + 1, dp(v, st, u);
}

void dfs(int u) {
	vis[u] = 1;
	for (auto v : G[u]) if (in[v] && !vis[v]) dfs(v);
}

bool check(vector<int> &vec) {
	for (int i = 1; i <= n; i ++) vis[i] = in[i] = 0;
	for (auto x : vec) in[x] = 1;
	int cnt = 0;
	for (auto x : vec) if (!vis[x]) dfs(x), cnt ++; 
	return cnt <= 2;
}

void solve() {
	n = read(), k = read();
	for (int i = 1; i <= n; i ++) G[i].clear();
	for (int i = 1; i < n; i ++) {
		int u = read(), v = read();
		G[u].push_back(v); G[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) f[i][i] = 0, dp(i, i, 0);
	int res = 0x3f3f3f3f;
	for (int i = 1; i < (1 << n); i ++) {
		int cnt = 0;
		vector<int> vec1, vec2;
		for (int j = 0; j < n; j ++) 
			if (i >> j & 1) vec1.push_back(j + 1), cnt ++;
			else vec2.push_back(j + 1);
		if (cnt == k && check(vec1)) {
			int maxd = 0;
			for (auto y : vec2) {
				int mind = 0x3f3f3f3f;
				for (auto x : vec1) mind = min(mind, f[y][x]); 
				maxd = max(maxd, mind);
			}
			res = min(res, maxd);
		}
	}
	printf("%d\n", res);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), T = read();
	while (T --) solve();
	return 0;
}
