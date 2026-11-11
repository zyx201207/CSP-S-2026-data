#include <stdio.h>
#include <string.h>
int a[200005];
char c[200005];
char buf[5];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; scanf("%d", &n);
	long long len = 0;
	for (int i = 0; i < n; i++) {
		buf[0] = buf[1] = buf[2] = buf[3] = buf[4] = 0;
		scanf("%d %s", a + i, buf);
		c[i] = buf[0];
		len += a[i];
	}
	long long res = 0, cu = 0;
	for (int l = 0, r = n - 1; cu < len;) {
		int mn = a[l];
		if (a[r] < mn) mn = a[r];
		cu += (mn * 2LL);
		int l0 = l, r0 = r;
		if (c[l] != c[r]) res += mn;
		if (a[l] == mn) l++;
		if (a[r] == mn) r--;
		a[l0] -= mn, a[r0] -= mn;
		if (l >= r) break;
	}
	printf("%lld", res);
	return 0;
} 
