#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define M 50
int n, m, t, i, j, k, l, a[N], b[N][M], c[M], d[N], g[N], s;
int main (){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	t=35;
	scanf ("%d %d", &n, &m);
	for (i=1; i<=n; i++) {
		scanf ("%d", &a[i]);
		k=a[i], j=0;
		while (k>0) c[++j]+=k%2, b[i][j]=k%2, k/=2;
	}
	for (i=t; i>=1; i--) {
		if (c[i]>=m) {
			d[i]=1;
			for (j=1; j<=t; j++) c[j]=0;
			for (j=1; j<=n; j++) {
				if (!b[j][i]) g[j]=1;
				if (g[j]) continue;
				k=a[j], l=0;
				while (k>0) c[++l]+=k%2, k/=2;
			}
		}
	}
	for (i=1; i<=t; i++) s+=d[i]<<i-1;
	printf ("%d", s);
	return 0;
}
