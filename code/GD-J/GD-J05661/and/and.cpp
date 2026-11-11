#include <stdio.h>
int n, m, a[200005];
int cpy[200005], len;
int main (void) {
	FILE *inf = fopen ("and.in", "r");
	FILE *outf = fopen ("and.out", "w");
	
	fscanf (inf, "%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)	fscanf (inf, "%d", &a[i]);
	int ans = 0;
	for (int exp = 29; exp >= 0; --exp) {
		len = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] & (1 << exp))	cpy[++len] = a[i];
		}
		if (len >= m) {
			ans |= (1 << exp);
			for (int i = 1; i <= len; ++i)	a[i] = cpy[i];
			n = len;
		}
	}
	fprintf (outf, "%d\n", ans);
	
	fclose (inf);
	fclose (outf);
	return 0;
}
