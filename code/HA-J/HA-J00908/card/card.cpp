#include <bits/stdc++.h>
using namespace std;

int n , m , a[50005], c[3005] , b[50005];

int main () {
	
	freopen ("card.in " , "r" , stdin);
	freopen ("card.out" , "w" , stdout);
	scanf ("%d%d", &n , &m);
	for (int i = 1 ; i <= n ; i ++) 
		scanf ("%d", &a[i]);
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = i ; j <= n ; j ++) {
			long long k = a[j] ,v;
			bool ok = true;
			for (int p = i ; p < j ; p ++) {
				if (b[p] == k) {
					ok = false ;
					v = i;
					break;
				}
			}
			if (!ok) 
				for (int p = v ; p < j ; p ++) 
					b[p] --;
			b[j] = k;
		}
		for (int j = i ; j <= n ; j ++) {
			c[b[j]] ++;
		}
	}
	for (int i = 1 ; i <= m ;i ++) 
		printf ("%d ", c[i]);
	
	return 0;
}
