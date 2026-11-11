#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 200005 ;
int n ;
int a[MAXN] ;
char c[MAXN] ;
long long sum , ans ;
int l[MAXN] , r[MAXN] ;
//long long b[i] ;
string s ;
int main () {
//	freopen ("string.in","r",stdin) ;
//	freopen ("string.out","w",stdout) ; 
	
	ios::sync_with_stdio (false) ;
	cin.tie(0) , cout.tie(0) ; 
	
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] >> c[i] ;
		sum += a[i] ;
		for ( int j = 1 ; j <= a[i] ; j ++ ) s += c[i] ;
//		b[i] = sum ;
	}
	cout << s ;
	for ( int i = 0 ; i < (s.size() / 2) ; i ++ ) if (s[i] != s[s.size()-i-1]) ans ++ ;
	
	cout << ans ;
	
	return 0 ;
} 
/*
3
2 a
2 b
1 c

*/
