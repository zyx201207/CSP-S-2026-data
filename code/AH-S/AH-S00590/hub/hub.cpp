#include <bits/stdc++.h>

namespace IO {
	#define gc getchar_unlocked
	#define pc putchar_unlocked
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	inline int read() {
		bool f = 0;
		char ch = gc();
		while (!isdigit(ch)) {
			if (ch == '-') f = 1;
			ch = gc();
		}
		
		int x = 0;
		while (isdigit(ch)) {
			x = (x << 1) + (x << 3) + (ch ^ 48);
			ch = gc();
		}
		
		if (f) return -x;
		return x;
	}
	inline void read(int &a) {a = read();}
	inline void read(int &a, int &b) {a = read(); b = read();}
	inline void read(int &a, int &b, int &c) {a = read(); b = read(); c = read();}
	
	void write(int x) {
		if (x < 0) {
			pc('-');
			x = -x;
		}
		if (x > 9) write(x / 10);
		pc(x % 10 + 48);
	}
}
using namespace IO;
using namespace std;
const int N = 1e6 + 10;

int n, k, sz[N], dis1[N], dis2[N];
int W[3];
vector<int> G[N];

void dfs(int u, int fa) {
	sz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	sz[u] = max(sz[u], n - sz[u]);
	if (sz[u] <= n / 2) W[++W[0]] = u;
} 

void dfs2(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs2(v, u);
		dis1[v] = dis1[u] + 1;
	}
}

void dfs3(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs2(v, u);
		dis2[v] = dis2[u] + 1;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int Case, T;
	read(Case, T);
	while (T--) {
		read(n, k);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			read(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		memset(sz, 0, sizeof(sz));
		memset(dis1, 0, sizeof(dis1));
		memset(dis2, 0, sizeof(dis2));
		W[0] = W[1] = W[2] = 0;
		dfs(1, 0);
		
		dfs2(W[1], 0);
		if (W[0] == 2) {
			dfs3(W[2], 0);
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				if (i == W[1] || i == W[2]) continue;
				ans += min(dis1[i], dis2[i]);
			}
			printf("%lld\n", ans);
		} else {
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				if (i == W[1]) continue;
				ans += dis1[i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
