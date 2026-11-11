#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n, m, i, j, k, l, r, a[N];
char c[N];
long long s;
int main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	scanf ("%d", &n);
	for (i=1; i<=n; i++) {
		scanf ("%d %c", &a[i], &c[i]);
	}
	l=1, r=n;
	while (l<r) {
		k=min (a[l], a[r]);
		if (c[l]!=c[r]) s+=k;
		a[l]-=k, a[r]-=k;
		if (a[l]<=0) l++;
		if (a[r]<=0) r--;
	}
	printf ("%lld", s);
	return 0;
} 
