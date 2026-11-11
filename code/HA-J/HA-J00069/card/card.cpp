#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], p[N], c[N], ans[N], d[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	c[n + 1] = n + 1;
	for (int i = n; i; i--) {
		if (p[a[i]]) {
			c[i] = c[p[a[i]]];
		} else {
			c[i] = i + 1;
		}
		p[a[i]] = i;
		d[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		d[c[i]] += d[i];
		ans[a[i]] += d[i];
	}
	for (int i = 1; i <= m; i++) {
		printf("%d", ans[i]);
		if (i != m) printf(" ");
	}
	printf("\n");
	return 0;
}