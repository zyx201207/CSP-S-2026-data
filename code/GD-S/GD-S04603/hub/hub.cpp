#include <bits/stdc++.h>
using namespace std;
#define N 2000005
int n, m, t, i, j, k, l, x, y, ss, b[N], c[N], f[N], h[N], g[N];
struct AB {
	int x, y, n;
}a[N+N];
void cun (int x, int y) {
	a[++k].x=x, a[k].y=y;
	a[k].n=h[x], h[x]=k;
}
void shu (int x, int p) {
	int i;
	for (i=h[x]; i; i=a[i].n) {
		y=a[i].y;
		if (y==p) continue;
		f[y]=min (f[y], f[x]+1);
		shu (y, x);
	}
}
void dashu (int x, int p) {
	int i;
	c[x]=1;
	for (i=h[x]; i; i=a[i].n) {
		y=a[i].y;
		if (y==p) continue;
		if (!b[y]) continue;
		dashu (y, x);
	}
}
void dfs (int k, int x) {
	if (k>n) {
		if (x!=m) return ;
		int i, j, s=0;
		for (i=1; i<=n; i++) {
			c[i]=0;
			if (b[i]) f[i]=0;
			else f[i]=1e9;
		}
		for (i=1; i<=n; i++) {
			if (b[i]) break;
		}
		shu (i, 0);
		dashu (i, 0);
		for (i=1; i<=n; i++) {
			if (b[i]&&c[i]==0) break;
		}
		shu (i, 0);
		dashu (i, 0);
		for (i=1; i<=n; i++) {
			if (b[i]&&c[i]==0) break;
		}
		if (i<=n) return ;
		for (i=1; i<=n; i++) {
			s=max (s, f[i]);
		}
		if (i>n) {
			ss=min (s, ss);
		}
	}
	else {
		if (x+n-k+1<m) return ;
		if (x+n-k+1==m) {
			int i;
			for (i=k; i<=n; i++) b[i]=1;
			dfs (n+1, m);
		}
		b[k]=0;
		dfs (k+1, x);
		b[k]=1;
		dfs (k+1, x+1);
	}
}
int main (){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	scanf ("%*d %d", &t);
	while (t--) {
		k=0;
		ss=1e9;
		scanf ("%d %d", &n, &m);
		for (i=1; i<=n; i++) h[i]=0;
		for (i=1; i<n; i++) {
			scanf ("%d %d", &x, &y);
			cun (x, y);
			cun (y, x);
		}
		dfs (1, 0); 
		printf ("%d\n", ss);
	}
	return 0;
} 
