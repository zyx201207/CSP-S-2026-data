#include<cstdio>
#include<cstring>
int constexpr N = 2e6 + 1;
int c, t, n, d, pos[N], to[N], vis[N], mini, r;
int min(int a, int b) {
	return a < b ? a : b;
}
int dfs(int f, int t, int p = 0) {
	int r = 0;
	if(f == t) return 1;
	for(int i = t;i >= f + 1;i--) {
		//printf("%d %d %d\n", f, t, i);
		if(pos[f] + d < pos[i]) {
			continue;
		}
		if(vis[i]) continue;
		if(i == t) {
			mini = min(mini, p);
			return 1;
		}
		vis[i] = 1;
		r += dfs(i, t, p + 1);
		if(r > 2) return r;
	}
	return r;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) {
		scanf("%d%d", &n, &d);
		for(int i = 1;i <= n;i++) {
			scanf("%d", &pos[i]);
		}
		for(int i = 1;i < n;i++) {
			to[i] = i;
			vis[i] = 1;
			for(int j = i + 1;j <= n;j++) {
				if(to[i] + d >= pos[j]) to[i] = j;
				else {
					break;
				}
				memset(vis, 0, sizeof vis);
				mini = 1e9 + 7;
				r += dfs(i, j) == 2;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}
