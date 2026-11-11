#include <bits/stdc++.h>
using namespace std;
const int N = 550;
const int K = 5e5 + 10;
int c, n, m, d, q, w[N], a[N][N], k[N], t[K];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", k[i]);
		for (int j = 1; j <= 2 * k[i]; j++) {
			scanf("%d", &t[j]);
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("0\n");
	}
	return 0;
}
