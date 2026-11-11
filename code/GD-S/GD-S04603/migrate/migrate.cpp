#include <bits/stdc++.h>
using namespace std;
#define N 2000005
long long n, m, t, s, i, j, k, l, x, y, xx, yy, a[N], b[N], d[N];
int main (){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%*d %lld", &t);
	while (t--) {
		s=0;
		scanf ("%lld %lld", &n, &m);
		for (i=1; i<=n; i++) {
			scanf ("%lld", &a[i]);
		}
		sort (a+1, a+n+1);
		for (x=1; x<=n; x++) {
			for (y=x+1; y<=n; y++) {
				xx=x, k=0, b[++k]=x;
				while (xx<y) {
					if (a[xx]+m<a[xx+1]) break;
					yy=upper_bound (a+xx+1, a+y+1, a[xx]+m)-a;
					b[++k]=xx=yy-1;
				}
				if (xx<y) continue;
				xx=y, j=k+1, d[--j]=y;
				while (xx>x) {
					if (a[xx]-m>a[xx-1]) break;
					if (a[xx]-m<=a[x]) {
						d[--j]=x;
						break;
					}
					yy=lower_bound (a+x, a+xx, a[xx]-m)-a;
					d[--j]=xx=yy;
				}
				xx=0;
				for (j=1; j<=k; j++) {
					if (b[j]-d[j]>1) break;
					if (b[j]!=d[j]) xx++;
				}
				if (xx==1&&j>k) s++;
			}
		}
		printf ("%lld\n", s);
	}
	return 0;
}
