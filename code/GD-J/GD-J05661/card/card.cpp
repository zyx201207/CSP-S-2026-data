#include <stdio.h>
int n, m, a[500005];
int last[300005], ans[300005];
int BIT[500005];
void update (int pos, int val) {
	if (pos == 0 || val == 0)	return;
	for (; pos <= n; pos += (pos & ((~pos) + 1)))	BIT[pos] += val;
}
int query (int pos) {
	int res = 0;
	for (; pos; pos &= (pos - 1))	res += BIT[pos];
	return res;
}
int main (void) {
	FILE *inf = fopen ("card.in", "r");
	FILE *outf = fopen ("card.out", "w");
	
	fscanf (inf, "%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		fscanf (inf, "%d", &a[i]);
		last[a[i]] = i;
		update (i, 1);
	}
	for (int i = 1; i <= n; ++i) {
		int cnt = query (i);
		update (i, -cnt);
		update (last[a[i]], cnt);
	}
	for (int i = 1; i <= n; ++i)	ans[a[i]] += query (i);
	for (int i = 1; i <= m; ++i)	fprintf (outf, "%d ", ans[i]);
	
	fclose (inf);
	fclose (outf);
	return 0;
}
