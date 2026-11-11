#include <bits/stdc++.h>
using namespace std;
#define N 500005
long long n, m, ss, i, j, k, l, r, c, a[N], s[N];
int qiu (long long x, long long y) {
	long long xx=s[y]-s[x-1], yy=a[y]*(y-x+1);
	if (yy-xx<=m) return 1;
	else return 0;
}
int main (){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%lld %lld", &n, &m);
	for (i=1; i<=n; i++) {
		scanf ("%lld", &a[i]);
	}
	sort (a+1, a+n+1);
	for (i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	for (i=1; i<=n; i++) {
		l=1, r=i;
		while (l<r) {
			c=l+r>>1;
			if (qiu (c, i)) r=c;
			else l=c+1;
		}
		if (i-l+1>ss) ss=i-l+1;
	}
	printf ("%lld", ss);
	return 0;
} 
