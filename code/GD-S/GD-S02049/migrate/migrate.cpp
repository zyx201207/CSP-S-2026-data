#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const long long INF = 2000005;
int dp[ 505 ][ 505 ] , ap[ MAXN ], ans = 0 , min;
int ser[ 505 ][ 505 ] ;
int c , t , n , m;
int up( int s , int e ){
	int ans = 0 ;
	while( s < e ){
		int k = ap[ s ] + m;
		s = lower_bound( ap + s + 1 , ap + e + 1 , k ) - ap ;
		ans++;
	}
	return ans;
}
int dfs( int s , int e , int k , int deep ){
	if( k > deep ){
		return 0;
	}
	else if( s == e && k == deep ){
		return 1;
	}
	int k1 = ap[ s ] + m;
	int u = 0;
	int s1 = lower_bound( ap + s , ap + e , k1 ) - ap;
	if( ap[ s1 ] - ap[ s ] > m ){
		return 0;
	}
	for( int i = s + 1 ; i <= s1 ; i ++ ){
		u += dfs( i , e , k++ , deep );
	}
	return u;
}
int main(){
	freopen( "migrate.in" , "r" , stdin );
	freopen( "migrate.out" , "w" , stdout );
	cin >> c >> t;
	while( t-- ){
		ans = 0;
		cin >> n >> m;
		int n1 = n ;
		bool k = 0;
		for( int i = 1 ; i <= n1 ; i ++ ){
			cin >> ap[ i ];
		}
		ap[ 505 ] = INF;
		for( int i = 1 ; i <= n - 2 ; i ++ ){
			for( int j = i + 2 ; j <= n ; j ++ ){
				int maxx = up( i , j );
				int g = dfs( i , j , 1 , maxx );
				if( g == 2 ){
					ans ++;
				}
			}
		}	
		cout << ans << '\n';
	}
	return 0;
} 
