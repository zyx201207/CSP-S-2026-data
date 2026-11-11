#include <bits/stdc++.h>
using namespace std ;
int n , ans ;
long long m , a[5000005] , b[5000005] , k[5000005] , c[5000005] ;
bool checkA () {
	for (int i = 1 ; i <= n ; i++) {
		if (a[i] != i) return 0 ;
	}
	return 1 ;
}
void fA () {
	long long sum = 0 ;
	for (int i = 1 ; i <= n - 1 ; i++) {
		sum += i ;
		if (sum > m) {
			cout << i ;
			return ;
		}
	}
	cout << n ;
}
bool checkB () {
	for (int i = 3 ; i <= n ; i++) {
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			return 0 ;
		}
	}
	return 1 ;
}
void fB () {
	long long k = a[2] - a[1] , sum = 0 ;
	for (int i = 1 ; i <= n - 1 ; i++) {
		sum += k * i ;
		if (sum > m) {
			cout << i ;
			return ;
		}
	}
	cout << n ;
}
void f () {
	c[1] = a[1] ;
	for (int i = 2 ; i <= n ; i++) {
		c[i] = c[i - 1] + a[i] ;
		b[i] = a[i] - a[i - 1] ;
		k[i] = b[i] * (i - 1) + k[i - 1] ;
	}
	bool q = 1 ;
	for (int i = 2 ; i <= n ; i++) {
//		cout << i << " " ;
		q = 1 ;
		for (int j = i - 1 ; j >= 1 ; j--) {
			long long num = k[i] - ((j - 1) * a[i] - c[j - 1]) ;
			if (num > m) {
				ans = max (ans , i - j) ;
				q = 0 ;
				break ;
			}
		}
		if (q) {
			ans = max (ans , i) ;
		}
	}
}
int main () {
	freopen ("crystal.in" , "r" , stdin) ;
	freopen ("crystal.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
	}
	sort (a + 1 , a + 1 + n) ;
	if (checkA ()) {
		fA () ;
		return 0 ;
	}
	else if (checkB ()) {
		fB () ;
		return 0 ;
	}
	else {
		f () ;
		cout << ans ;
	}
	return 0 ;
} 
