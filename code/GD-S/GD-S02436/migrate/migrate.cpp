#include<bits/stdc++.h>
using namespace std;

#define gc getchar

typedef long long ll;
typedef pair< ll , ll > P;
const ll inf = 1000000000000000000 + 7;
const ll max_n = 2e6 + 7;
ll C , T , n ;
ll d , x[ max_n ];
vector< vector< P > > adj; 
vector< ll > dist , cnt ;

inline ll re(){
	ll num = 0 , f = 1 ; char x = gc();
	while( !isdigit( x ) && x != '-' ) x = gc();
	if( x == '-' ) f = -1 , x = gc();
	while( isdigit(x) ) num = num * 10 + x - '0' , x = gc();
	return num * f; 
}

void init(){
	adj.clear();
	adj.resize( n + 1 );
}
void init2(){
	dist.clear();
	cnt.clear();
	dist.resize( n + 1 , inf );
	cnt.resize( n + 1 , 1 );
}
void dijkstra( int st ){
	priority_queue< P , vector< P > , greater< P > > pq;
	pq.emplace( 0 , st );
	dist[ st ] = 0 ;
	
	while( !pq.empty() ){
		P cur = pq.top();
		pq.pop();
		ll u = cur.second , dis = cur.first;
		if( dist[u] < dis ) continue;
		
		for( P tmp : adj[u] ){
			ll v = tmp.second , w = tmp.first;
			if( dist[v] > dist[u] + w  ){
				dist[v] = dist[u] + w , cnt[ v ] = cnt[u];
				pq.emplace( dist[v] , v );
			}else if( dist[v] == dist[u] + w  )
				cnt[v] += cnt[u];
			
		}
	}
}
int main(){
	
	freopen( "migrate.in" , "r" , stdin );
	freopen( "migrate.out" , "w" , stdout );
	
	C = re() , T = re();
	while( T-- ){
		ll ans = 0;
		n = re() , d = re();
		init();
		for( int i = 1 ; i <= n ; i++ )
			x[i] = re();
		
		
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = 1 ; j <= n ; j++ ){
				if( i == j ) continue;
				if( llabs( x[i] - x[j] ) <= d ){
					adj[i].emplace_back( 1 , j );
//					cout << i << " " << j << "\n";
				}
			}
		}
		for( int i = 1 ; i <= n ; i++ ){
			init2();
			dijkstra( i );
//			printf( "dist%d\n" , i );
//			for( int j = 1 ; j <= n ; j++ )
//				printf( "%d " , dist[j] );
//			printf( "\n" );
//			for( int j = 1 ; j <= n ; j++ )
//				printf( "%d " , cnt[j] );
//			printf( "\n" );
			for( int j = 1 ; j <= n ; j++ )
				if( cnt[j] == 2 ) ans ++;
		}
		printf( "%lld\n" , ans/2 );
	}

}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
