#include <stdio.h>
int m, n, c, d, q, w[500005], x, y, i;
int a[505], t[505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(i=1; i<=m; i++) scanf("%d", &w[i]);
	for(i=1; i<=n; i++) scanf("%d%d", &a[i], &t[i]);
	for(i=1; i<=q; i++){
		scanf("%d%d", &x, &y);
		printf("%d\n", (y-x) * t[1]);
	}
	return 0;
}
