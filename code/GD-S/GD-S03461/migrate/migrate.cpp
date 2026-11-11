#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e6 + 100 ;
int c , t , n , max_distance ;
ll x[N] , dis[N] , sum[N] , tot , answer , min_step ;
void dfs( int step , int u , int end ) {
	if( u == end ) { 
		if( step < min_step ) tot = 1 ;
		if( step == min_step ) tot++ ;
		return ;
	} 
	for( int i = u + 1 ; i <= end ; i++ ) if( sum[i] - sum[u] <= max_distance ) dfs( step + 1 , i , end ) ;
}
int main() {
	freopen( "migrate.in" , "r" , stdin ) , freopen( "migrate.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) , cin.tie(0) ;
	cin>>c>>t ;
	while( t-- ) {
		cin>>n>>max_distance ;
		for( int i = 1 ; i <= n ; i++ ) cin>>x[i] , dis[i] = x[i] - x[i-1] ;
		for( int i = 1 ; i <= n ; i++ ) sum[i] = sum[i-1] + dis[i] ;
		for( int i = 1 ; i <= n ; i++ ) for( int j = i + 1 ; j <= n ; j++ ) { tot = 0 , min_step = 0x3f3f3f3f ; dfs( 0 , i , j ) ; answer += ( tot == 2 ) ; }
		cout<<answer<<"\n" ;
	}
	return 0 ;
}
