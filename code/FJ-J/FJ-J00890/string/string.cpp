#include <bits/stdc++.h>
using namespace std ;

long long n , a[200200] ; char c[200200] ;

int main ()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin >> n ; long long sum = 0 ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> c[i] ; sum += a[i] ;
	}
	long long ans = 0 ;
	for (int i = 1 ; i*2 <= n ; i++) {
		if (c[i] != c[n-i+1]) {
			int cha = a[i] - a[n-i+1] ;
			if (cha >= 0) ans += a[n-i+1] ;
			else {
				ans += a[i] ;
			}
		}
		else {
			if (n > 2) ans += abs(a[i] - a[n-i+1]) ;
		}
	}
	cout << ans ;
	
	return 0 ;
}
