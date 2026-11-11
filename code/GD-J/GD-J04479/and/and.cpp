#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 5 ;
long long n , m , a[N] ;
int main(){
	freopen( "and.in" , "r" , stdin ) ;
	freopen( "and.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	sort( a + 1 , a + n + 1 , greater<long long>() ) ;
	int t = a[1] ;
	for( int i = 2 ; i <= m ; i++ ){
		t &= a[i] ;
	}
	cout << t ;
	return 0 ;
}
