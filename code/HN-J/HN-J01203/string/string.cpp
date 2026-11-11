#include <stdio.h>
#ifndef __min
	#define __min(a, b) ((a) < (b) ? (a) : (b))
#endif

int a[200000];
char c[200000];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, l, r;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %c", a+i, c+i);
	l = 0, r = n-1;
	while (l < r) {
		int x = __min(a[l], a[r]);
		if (c[l] != c[r])
			ans += x;
		a[l] -= x, a[r] -= x;
		if (a[l] == 0)
			l++;
		if (a[r] == 0)
			r--;
	}
	printf("%lld", ans);
	return 0;
}

