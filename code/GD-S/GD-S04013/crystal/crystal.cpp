#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 5 ;
long long n , m , a[N] , c[N] , cnt , sum , maxn , minn1 , maxn2 = -1 ;
bool f = 1 ;
long long check( int x ){
	for( int i = 1 ; i <= n ; i++ ){
		c[i] = abs( a[i] - x ) ;
	}
	sort( c + 1 , c + n + 1 ) ;
	int id = 1 ;
	sum = 0 ;
	for( ; id <= n && sum <= m ; id++ ){
		sum += c[id] ;
	}
	if( id == n + 1 ){
		return n ;
	}
	return max( 0 , id - 2 ) ;
}
int main(){
	freopen( "crystal.in" , "r" , stdin ) ;
	freopen( "crystal.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) ;cin.tie(0) ;cout.tie(0) ;
	cin >> n >> m ;
	long long t = a[2] - a[1] ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
		if( i != 1 ){
			maxn = max( maxn , a[i] ) ;
			minn1 = min( minn1 , a[i] ) ;
		}else{
			maxn = a[i] ;
			minn1 = a[i] ;
		}
		if( a[i] == i ){
			cnt++ ;
		}
		if( i >= 3 && a[i] - a[i - 1] != t ){
			f = 0 ;
		}
	}
	sort( a + 1 , a + n + 1 ) ;
	if( cnt == n || f == 1 ){
		int x = n / 2 + 1 ;
		cout << check(x) ;
		return 0 ;
	}else{
		for( int i = minn1 ; i <= maxn ; i++ ){
			maxn2 = max( maxn2 , check(i) ) ;
		}
	}
	cout << maxn2 ;
	return 0 ;
}
