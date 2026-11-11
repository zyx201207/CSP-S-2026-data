#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int c, t, n, k, vis[N], head[N], nxt[N<<1], to[N<<1], mx[N], tmp, dep[N], fat[N], tot, root, a[N], w[N];
void add(int x, int y) {
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	fat[u] = fa;
	for (int i = head[u]; i; i = nxt[i]) {
		int y = to[i];
		if (y == fa) continue;
		dfs(y, u);
	}
	if (dep[u] > tmp) {
		tmp = dep[u];
		root = u;
	}
}
void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int y = to[i];
		if (y == fa || vis[y] == 1) continue;
		dfs1(y, u);
	}
	if (dep[u] > tmp) {
		tmp = dep[u];
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		scanf("%d%d", &n, &k);
		tot = 0;
		for (int i = 1; i <= n; i++) head[i] = 0, vis[i] = 0;
		for (int x, y, i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		dfs(1, 0);
		int tmp = root;
		dfs(root, 0);
		int m = 0;
		for (int i = root; i; i = fat[i]) {
			a[++m] = i;
			vis[i] = 1;
			if (i == tmp) break;
		}
		printf("%d\n", m / k);
	}
	return 0;
}
