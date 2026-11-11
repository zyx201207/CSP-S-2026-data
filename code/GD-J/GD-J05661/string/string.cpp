#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef long long int llong;
int n;
llong a[200005];
char c[200005];
llong * binary_search (llong *arr, llong size, llong key) {
	llong *l = arr, *r = arr + size;
	while (l < r) {
		llong *mid = ((r - l) >> 1) + l;
		if (*mid >= key)	r = mid;
		else	l = mid + 1;
	}
	return r - 1;
}
int main (void) {
	FILE *inf = fopen ("string.in", "r");
	FILE *outf = fopen ("string.out", "w");
	
	fscanf (inf, "%d", &n);
	for (int i = 1; i <= n; ++i) {
		fscanf (inf, "%lld %c", &a[i], &c[i]);
		a[i] += a[i - 1];
	}
	llong L = (a[n] >> 1), R = (a[n] >> 1) + 1 + (a[n] % 2), ans = 0;;
	while (L >= 1 && R <= a[n]) {
		llong l = binary_search (a + 1, n, L) - a;
		llong r = binary_search (a + 1, n, R) - a + 1;
		llong len = min (L - a[l], a[r] - R + 1);
		if (c[l + 1] != c[r])	ans += len;
		L -= len, R += len;
	}
	fprintf (outf, "%lld\n", ans);
	
	fclose (inf);
	fclose (outf);
	return 0;
}
