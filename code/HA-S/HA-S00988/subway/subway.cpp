#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 5e5 + 5;
int c, n, m, d, q, ans;
int w[M], k[505], a[505][M], t[505][M];
void solve2(int x, int y) {
	int res = w[x] + w[y] + t[1][x] + t[1][y];
	bool flag1 = false, flag2 = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (a[i][j] == x) flag1 = true;
			if (a[i][j] == y) flag2 = true;
		}
	}
	if (!flag || !flag2) {
		res += t[1][x] * 2;
	}
	return res;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (c >= 12 && c <= 19) ans = solve2(x, y);
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
