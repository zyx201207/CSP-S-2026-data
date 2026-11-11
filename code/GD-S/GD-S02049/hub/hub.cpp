#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int INF = 500005;
long long ap[ 5005 ][ 5005 ] , r[ 5005 ];
long long c , n , m , d , q , l ;
long long a[ 505 ][ 505 ] , t[ 505 ][ 505 ];
long long k1[ 5005 ];
int main(){
	freopen( "hub.in" , "r" , stdin );
	freopen( "hub.out" , "w" , stdout );
	memset( ap , INF , sizeof( ap ) );
	cin >> c >> q;
	while( q-- ){
		cin >> n >> m;
		for( int i = 1 ; i < n ; i ++ ){
			int a1 , b1;
			cin >> a1 >> b1;
			ap[ a1 ][ b1 ] = 1;
		}
		for( int k = 1 ; k <= m ; k ++ ){
			for( int i = 1 ; i <= k ; i ++ ){	
				for( int j = k ; j <= m ; j ++ ){
					ap[ i ][ j ] = min( ap[ i ][ j ] , ap[ i ][ k ] + ap[ k ][ j ] );
					ap[ j ][ i ] = ap[ i ][ j ];
				} 
			} 
		}
		int ans;
		if( m % 2 == 1 ){
			m++;
		}
		m /= 2 ;
		while( m != 1 ){
			m /= 3;
			ans ++;
		}
		cout << ( ans ) / 2 + 1 << endl;
	}
	return 0;
} 
