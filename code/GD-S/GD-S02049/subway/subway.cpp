#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int INF = 500005;
long long ap[ 5005 ][ 5005 ] , r[ 5005 ];
long long c , n , m , d , q , l ;
long long a[ 505 ][ 505 ] , t[ 505 ][ 505 ];
long long k1[ 5005 ];
int main(){
	freopen( "subway.in" , "r" , stdin );
	freopen( "subway.out" , "w" , stdout );
	cin >> c >> n >> m >> d >> q;
	memset( ap , INF , sizeof( ap ) );
	for( int i = 1 ; i <= m ; i ++ ){
		cin >> k1[ i ];
	}
	for( int i = 1 ; i <= n ; i ++ ){
		cin >> l;
		r[ i ] = l;
		for( int j = 1 ; j <= l ; j++ ){
			int a1 , b1;
			cin >> a1 >>  b1;
			a[ i ][ j ] = a1;
			t[ a1 ][ i ] = b1;
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= r[ i ] ; j++ ){
			for( int k = 1 ; k <= r[ i ] ; k++ ){
				ap[ a[ i ][ j ] ][ a[ i ][ k ] ] = min( ap[ a[ i ][ j ] ][ a[ i ][ k ] ] , t[ a[ i ][ j ] ][ i ] + t[ a[ i ][ k ] ][ i ] );
			}
		} 
	}
	for( int k = 1 ; k <= m ; k ++ ){
		for( int i = 1 ; i <= k ; i ++ ){
			for( int j = k ; j <= m ; j ++ ){
				ap[ i ][ j ] = min( ap[ i ][ j ] , ap[ i ][ k ] + ap[ k ][ j ] );
				ap[ j ][ i ] = ap[ i ][ j ];
			} 
		} 
	}
	int from , to;
	for( int i = 1 ; i <= q ; i ++ ){
		cin >> from >> to;
		if( from == to ){
			cout << 0 << '\n';
			continue;
		}
		cout << ap[ from ][ to ] + k1[ from ] + k1[ to ] << '\n';
	}
	return 0;
} 
