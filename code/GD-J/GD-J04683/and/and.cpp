#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 200005 ;
int n , m ;
int a[MAXN] ;
int mmmm ;
int sum = 2147483647 ;
int mxxx ;
int main () {
	freopen ("and.in","r",stdin) ;
	freopen ("and.out","w",stdout) ; 
	
	ios::sync_with_stdio (false) ;
	cin.tie(0) , cout.tie(0) ; 
	
	cin >> n >> m ;
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
		//
//		if (i == 32768 ) mmmm = a[i] ;
		//
	}
	
	sort (a+1 , a+n+1) ;
	
//	for ( int i = 1 ; i <= n ; i ++ ) cout << a[i] << " " ;
//	cout << "\n" ;
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		int ans = 2147483647 ;
		for ( int j = i ; j - i <= m ; j ++ ) {
			ans &= a[j] ;
		}
		mxxx = max (mxxx , ans) ;
	}
	
	cout << mxxx ;
	
//	cout << "   " << a[32768] << " " << a[32767] << " " << a[32769];
	
	return 0 ;
} 
//i=32768 
