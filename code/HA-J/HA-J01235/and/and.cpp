#include<bits/stdc++.h>
using namespace std;

int n, m;
long long ans, a[200010];

void dfs (int d, long long num, int idx) {
	if (d == m) {
		ans = max (ans, num);
		return ;
	}
	
	for (int i = idx + 1; i <= n; i++) {
		long long t = num & a[i];
		dfs (d + 1, t, i);
	}
}

int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	scanf ("%d%d", & n, & m);
	for (int i = 1; i <= n; i++) 
		scanf ("%lld", & a[i]);
	for (int i = 1; i <= n - m; i++) dfs (1, a[i], i);
	printf ("%lld", ans);
	return 0;
}
