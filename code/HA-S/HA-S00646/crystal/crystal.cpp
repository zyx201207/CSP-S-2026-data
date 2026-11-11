#include <bits/stdc++.h>
using namespace std;

long long n, ans;
long long a[500005], c[500005], m;

void mergesort (int l , int r) {
	if (l >= r) 
		return;
	int mid = (l + r) / 2;
	mergesort (l , mid);
	mergesort (mid + 1 , r);
	int p1 = l, p2 = mid + 1 , tot = 0;
	while (p1 <= mid && p2 <= r) 
		if (a[p1] <= a[p2]) 
			c[++ tot] = a[p1 ++];
		else 
			c[++ tot] = a[p2 ++];
	while (p1 <= mid) 
		c[++ tot] = a[p1 ++];
	while (p2 <= r) 
		c[++ tot] = a[p2 ++];
	for (int i = 1 ; i <= tot ; i ++) 
		a[i + l - 1] = c[i]; 
}

int main () {
	
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	scanf ("%lld%lld", &n , &m);
	for (int i = 1; i <= n; i ++) 
		scanf ("%lld", &a[i]);
	mergesort (1 , n);	
	int cnt = 1;
	for (int i = 1; i <= n ;i ++) 
		if (a[i] == a[i - 1]) 
			cnt ++;
		else 
			break;
	while ((a[cnt + 1] - a[cnt]) * cnt <= m && cnt + 1 <= n) {
		cnt ++;
		for (int i = cnt - 1; i >= 1 && m >= 0 ;i --) 
			m -= (a[cnt] - a[i]) , a[i] = a[cnt]; 
	}
	for (int i = 1 ; i <= n ; i ++) 
		if (a[i] == a[cnt]) 
			ans ++;
	printf ("%lld", ans);
	 
	return 0;
}
