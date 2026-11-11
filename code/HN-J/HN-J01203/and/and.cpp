#include <stdio.h>
#include <string.h>

int a[200000];
int vis[200000];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	memset(vis, 1, sizeof(vis));
	int n, m, ans = 2147483647;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	for (int x = (1<<29); x; x >>= 1) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (vis[i] && a[i]&x)
				cnt++;
		if (cnt >= m)
			for (int i = 0; i < n; i++)
				if ((a[i]&x) == 0)
					vis[i] = 0;
	}
	for (int i = 0; i < n; i++)
		if (vis[i])
			ans &= a[i];
	printf("%d", ans);
	return 0;
}

