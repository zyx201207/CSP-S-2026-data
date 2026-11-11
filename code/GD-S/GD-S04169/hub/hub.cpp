#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector <int> v[N];
int st[N][17], dep[N], mx[N];
int n, d, id, x, y;
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	st[x][0] = fa, mx[x] = 1;
	for (int i = 1; i < 17; i++)
		st[x][i] = st[st[x][i - 1]][i - 1];
	for (auto y : v[x]) if (y != fa)
		dfs(y, x), mx[x] = max(mx[x], mx[y] + 1);
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 16; ~i; i--)
		if (dep[st[x][i]] >= dep[y])
			x = st[x][i];
	if (x == y) return x;
	for (int i = 16; ~i; i--)
		if (st[x][i] != st[y][i])
			x = st[x][i], y = st[y][i];
	return st[x][0];
}
int f[105][105], dis[105][105];
bool isanc[105][105];
void getans(int x, int fa, int banned) {
	mx[x] = 1;
	for (auto y : v[x]) if (y != fa) {
		getans(y, x, banned);
		if (y != banned) {
			mx[x] = max(mx[x], mx[y] + 1);
			for (int i = 0; i <= n; i++) f[x][i] += f[y][i];
		}
	}
	for (int i = 0; i < mx[x]; i++) ++f[x][i];
}
void work() {
	scanf("%d%d", &n, &d);
	if (id >= 13 && id <= 14) {
		if (d == n) puts("0");
		else if (d >= n / 2) puts("1");
		else printf("%d\n", (n / 2 - d - 1) / 4 + 2);
		while (n--) scanf("%d%d", &x, &y); return;
	}
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1; i < n; i++)
		scanf("%d%d", &x, &y),
		v[x].push_back(y),
		v[y].push_back(x);
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = dep[i] + dep[j] - 2 * dep[LCA(i, j)],
			isanc[i][j] = LCA(i, j) == i;
	int ans = 1e9;
	memset(f, 0, sizeof f), getans(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		int res = 0;
		while (f[i][res] > d) ++res;
		for (int j = 1; j <= n; j++) if (!isanc[i][j])
			res = max(res, dis[i][j]);
		ans = min(ans, res);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			memset(f, 0, sizeof f);
			getans(i, 0, j);
			int res = 0;
			while (f[i][res] + f[j][res] > d) ++res;
			ans = min(ans, res);
		}
	printf("%d\n", ans);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T;
	scanf("%d%d", &id, &T);
	while (T--) work();
	return 0;
}
