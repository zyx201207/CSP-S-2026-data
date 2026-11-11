#include <cstdio>

const int N = 6e5 + 1;

int n, m, lst[N], fst[N], a[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = n; i >= 1; i--) {
		if (!fst[a[i]]) fst[a[i]] = i;
		lst[i] = fst[a[i]];
	} for (int i = 1, j; i <= n; i++) {
		j = i; while (lst[j]) j = lst[j], ans[a[j]]++, j++;
	} for (int i = 1; i <= m; i++) { printf("%d", ans[i]); if (i != m) putchar(' '); }
	return 0;
}


