#include<bits/stdc++.h>
using namespace std;

#define gc getchar

typedef long long ll;
typedef pair< ll , ll > P ;
const int max_m = 5e5 + 7 , max_n = 507 ;
const ll inf = 1000000000000000000  + 7;
ll c , n , m , d , q , w[ max_m ]  ;
vector< P > cnt[ max_m ] ;
ll dis[507][507];

inline ll re(){
	ll num = 0 , f = 1 ; char x = gc();
	while( !isdigit( x ) && x != '-' ) x = gc();
	if( x == '-' ) f = -1 , x = gc();
	while( isdigit(x) ) num = num * 10 + x - '0' , x = gc();
	return num * f; 
}

int main(){
	
	freopen( "subway.in" , "r" , stdin );
	freopen( "subway.out" , "w" , stdout );
	
	c = re() , n = re() , m = re() , d = re() , q = re();
	for( int i = 1 ; i <= m ; i++ ) w[i] = re();
	for( int i = 1 ; i <= n ; i++ ){
		ll k = re();
		for( int j = 1 ; j <= k ; j++ ){
			ll a = re() , t = re(); 
			cnt[a].emplace_back( i , t );//ta ke yi gou tong zhe xie che zhan 
		}
	}
	memset( dis , 0x3f , sizeof( dis ) );
	for( int i = 0 ; i <= n ; i ++ ) dis[i][i] = 0;
	
	for( int k = 1 ; k <= m ; k++ ){
		for( int i = 0 ; i < (int)cnt[k].size()  ; i++ ){
			for( int j = i + 1 ; j < (int)cnt[k].size() ; j++ ){
				ll u = cnt[k][i].first , t1 = cnt[k][i].second ;
				ll v = cnt[k][j].first , t2 = cnt[k][j].second ;
				dis[u][v] = dis[v][u] = min( dis[u][v] , t1 + t2 );
			}
		}
	}
	//ran hou Floyd
//	for( int i = 1 ; i <= n ; i++ ){
//		for( int j = 1 ; j <= n ; j++ ){
//			printf( "%d " , dis[i][j] );
//		}
//		printf( "\n" );
//	}

	for( int k = 1 ; k <= n ; k++ ){
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = 1 ; j <= n ; j++ ){
				if( dis[i][j] > dis[i][k] + dis[k][j] )
					dis[i][j] = dis[i][k] + dis[k][j];//Floyd
			}
		}
	}
	
//	for( int i = 1 ; i <= n ; i++ ){
//		for( int j = 1 ; j <= n ; j++ ){
//			printf( "%d " , dis[i][j] );
//		}
//		printf( "\n" );
//	}

	for( int i = 1 ; i <= q ; i++ ){
		int x = re() , y = re();
		ll ans = inf;
		for( int i = 0 ; i < ( int )cnt[x].size() ; i++ ){
			for( int j = 0 ; j < ( int )cnt[y].size() ; j++ ){
				ll u = cnt[x][i].first , t1 = cnt[x][i].second ;
				ll v = cnt[y][j].first , t2 = cnt[y][j].second ; 
				ans = min( ans , 1ll*t1 + t2 + dis[u][v] + w[x] + w[y] );
			}
		}
		printf( "%lld\n" , ans );
	}
	
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
