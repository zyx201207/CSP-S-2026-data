#include <bits/stdc++.h>
using namespace std;

struct Node {
	int a , s;
}w[200005] , c[200005];

void mergesort (int l , int r) {
	if (l >= r) 
		return;
	int m = (l + r) / 2;
	mergesort(l , m);
	mergesort (m + 1 , r);
	int  p1 = l , p2 = m + 1 , tot = 0;
	while (p1 <= m && p2 <= r) 
		if (w[p1].s >= w[p2].s) 
			c[++ tot] = w[p1++];
		else 
			c[++ tot] = w[p2 ++];
	while (p1 <= m) 
		c[++ tot] = w[p1 ++]  ;
	while (p2 <= r) 
		c[++ tot] = w[p2 ++];
	for (int i = 1 ; i <= tot; i ++) 
		w[i + l - 1] = c[i];
}

int n, m, p[31];

int main () {
	
	freopen ("and.in" , "r" , stdin);
	freopen ("and.out" , "w" , stdout);
	scanf ("%d %d", &n , &m);
	for (int i = 1 ; i <= n ; i ++) 
		scanf ("%d", &w[i].a);
	for (int i = 0 ; i <= 30 ; i ++) 
		p[i] = pow(2 , i);
	for (int i = 1 ; i <= n ; i ++) {
		int j = 0;
		for (; p[j] <= w[i].a ; j ++) 
		w[i].s = j;
	}
	mergesort (1 , n);
	long long maxx = -1 << 30;
//	for (int i = 1 ; i <= m ; i ++) 
//		printf ("%d ", w[i].a);
	long long ans = w[1].a;
	for (int i = 1 ; i <= n - m + 1 ; i ++) {
		ans = w[i].a;
		for (int j = 1 ; j <= m; j ++)
			ans &= w[i + j - 1].a;
		if (ans >= maxx) {
			maxx = ans;
		}
 	}
	printf ("%lld", maxx);
//	printf ("Time : %d", clock());
	
	return 0;
} 
