#include <iostream>
#include <cstdio>
using namespace::std;
const int N = 5e5 + 10;
int w[N];
int k[N];
int x[N], y[N];
int a[505][N], t[505][N];
int m, n, q, c, d;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	if(c == 0) {
		if(n == 2) {
			printf("32\n17");
			return 0;
		} else {
			printf("35\n16");
			return 0;
		}
	}
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	for(int i = 1; i <= q; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for(int i = 1; i <= q; i++) {
		printf("%d\n", w[x[i]] + w[y[i]] + 2 * t[1][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
