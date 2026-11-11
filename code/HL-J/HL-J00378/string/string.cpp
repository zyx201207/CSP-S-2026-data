#include <bits/stdc++.h>
using namespace std ;
int n ;
long long sum ;
struct xxx {
	int num ;
	char p ;
} a[5000005] ;
void f (int x , int l , int r) {
	if (x == 1) {
		if (a[l].p == a[r].p) return ;
		else sum += a[l].num ;
	}
	if (x == 2) {
		if (a[l].p == a[r].p) return ;
		else sum += a[r].num ;
	}
	if (x == 3) {
		if (a[l].p == a[r].p) return ;
		else sum += a[l].num ;
	}
}
int main () {
	freopen ("string.in" , "r" , stdin) ;
	freopen ("string.out" , "w" , stdout) ;
	cin >> n ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i].num >> a[i].p ;
	}
	int l = 1 , r = n ;
	while (l <= r) {
		if (a[l].num == a[r].num) {
			f (1 , l , r) ;
			l++ ; r-- ;
		}
		else if (a[l].num > a[r].num) {
			f (2 , l , r) ;
			a[l].num -= a[r].num ;
			r-- ;
		}
		else if (a[l].num < a[r].num) {
			f (3 , l , r) ;
			a[r].num -= a[l].num ;
			l++ ;
		}
	}
	cout << sum ;
	return 0 ; 
}
