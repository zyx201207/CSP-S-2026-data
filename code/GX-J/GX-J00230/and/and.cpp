#include<bits/stdc++.h>
using namespace std;

int n, m ;
int a[114514] ;
int ans ;

int main() {
	freopen("ans.in", "r", stdin ) ;
	freopen("ans.out", "w",stdout ) ;
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}
	sort(a+1, a+n+1) ;
	ans = a[n] ;
	for( int i = 1 ; i < m ; i ++ ) {
		ans = ans & a[n-i] ;
	}
	cout << ans ;
	return 0 ;
}
