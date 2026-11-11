#include <bits/stdc++.h>
using namespace std;
#define N 300005
int n, m, i, j, k, l, a[N], c[N], f[N], d[N], b[N], g[N];
int main (){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	if (n>5000) {
		for (i=1; i<=n; i++) {
			scanf ("%d", &a[n-i+1]);
		}
		for (i=1; i<=n; i++) {
			if (c[a[i]]) {
				for (j=c[a[i]]+1; j<i; j++) {
					if (b[j]) {
						for (k=b[j]+1; k<j; k++) {
							if (g[k]) continue;
							d[k]--;
							if (d[k]<=0) {
								f[a[k]]+=n-i+1;
							}
						}
						b[j]=0;
					}
					if (g[j]) continue;
					f[a[j]]-=n-i+1, d[j]++;
				} 
				g[i]=1, b[i]=c[a[i]];
			}
			else c[a[i]]=i, f[a[i]]+=n-i+1;
		}
		for (i=1; i<=m; i++) printf ("%d ", f[i]);		
	}
	else {
		for (i=1; i<=n; i++) {
			scanf ("%d", &a[i]);
		}
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) c[a[j]]=d[j]=b[j]=0;
			for (j=i; j<=n; j++) {
				if (c[a[j]]) {
					for (k=d[c[a[j]]]; k; k=d[k]) {
						c[a[k]]=0;
					}
					l=b[c[a[j]]];
					d[l]=j, b[j]=l, d[j]=0;
					b[c[a[j]]]=d[c[a[j]]]=0;
					c[a[j]]=j;
				}
				else {
					c[a[j]]=j;
					d[j-1]=j;
					b[j]=j-1;
					d[j]=0;
				}
			}
			for (j=1; j<=m; j++) {
				if (c[j]) f[j]++;
			}
		}
		for (i=1; i<=m; i++) printf ("%d ", f[i]);
	}
	return 0;
}
