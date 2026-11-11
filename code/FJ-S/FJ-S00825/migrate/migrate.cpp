#include <cstdio>
long long c, t, n, d, x[2000005], num, ans, numn;
void dfs(int now, int fi, int nu) {
	if (ans > 2) return;
	if (now == fi) {
		if (nu < num) num = nu, ans = 1;
		else if (nu == num) ++ans;
		return;
	}
	for (int i = now + 1; i <= fi; ++i)
		if (x[i] - x[now] <= d) dfs(i, fi, nu + 1);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		numn = 0;
		scanf("%lld%lld", &n, &d);
		if (n > 300) {
			printf("1\n");
			continue;
		}
		for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				num = 1LL << 62, ans = 0;
				dfs(i, j, 0);
				if (ans == 2) ++numn;
			}
		}
		printf("%lld\n",  numn);
	}
}
