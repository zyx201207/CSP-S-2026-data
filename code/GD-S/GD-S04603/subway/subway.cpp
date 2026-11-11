#include <bits/stdc++.h>
using namespace std;
#define N 501
#define M 500001
int n, m, t, ak, tt, d[N][N], w[M], h[N], ac[N], cc[N][M], i, j, k, l, x, y, ax, by;
long long s, c, f[N], z;
set <int> tr;
struct AB {
	long long x, y, z, n;
}a[N*N];
void cun (long long x, long long y, long long z) {
	a[++k].x=x, a[k].y=y, a[k].z=z;
	a[k].n=h[x], h[x]=k;
}
int main (){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%*d %d %d %d %d", &n, &m, &ak, &tt);
	for (i=1; i<=m; i++) scanf ("%d", &w[i]);
	for (i=1; i<=n; i++) {
		scanf ("%d", &ac[i]);
		for (j=1; j<=ac[i]; j++) {
			scanf ("%d %d", &d[i][j], &t);
			cc[i][d[i][j]]=t;
		}
	}
	for (i=1; i<=n; i++) {
		for (j=i+1; j<=n; j++) {
			s=1e16;
			for (x=1; x<=m; x++) {
				if (cc[i][x]&&cc[j][x]) {
					if (cc[i][x]+cc[j][x]<s) s=cc[i][x]+cc[j][x];
				}
			}
			if (s<1e13) {
				cun (i, j, s);
				cun (j, i, s);
			}
		}
	}
	while (tt--) {
		c=0;
		k=0;
		tr.clear ();
		for (i=1; i<=n; i++) f[i]=1e16;
		scanf ("%d %d", &ax, &by);
		for (i=1; i<=n; i++) {
			if (cc[i][ax]) tr.insert (i), f[i]=cc[i][ax];
		}
		while (tr.size ()) {
			x=*tr.begin (), tr.erase (tr.begin ());
			for (j=h[x]; j; j=a[j].n) {
				y=a[j].y, z=a[j].z;
				if (f[x]+z<f[y]) {
					tr.insert (y);
					f[y]=f[x]+z;
				}
			}
		}
		s=1e16;
		for (i=1; i<=n; i++) {
			if (cc[i][by]) {
				if (f[i]+cc[i][by]<s) s=f[i]+cc[i][by];
			}
		}
		printf ("%lld\n", s+w[ax]+w[by]);
	}
	return 0;
}
