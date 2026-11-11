#include<bits/stdc++.h>
using namespace std;

#define gc getchar

typedef long long ll;
typedef pair< ll , int > P;
const int max_n = 5e5 + 7;
ll n , m , a[ max_n ] , sum[ max_n ] , ans ;

inline ll re(){
	ll num = 0 , f = 1 ; char x = gc();
	while( !isdigit( x ) && x != '-' ) x = gc();
	if( x == '-' ) f = -1 , x = gc();
	while( isdigit(x) ) num = num * 10 + x - '0' , x = gc();
	return num * f; 
}

int main(){
	
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
	
	n = re() , m = re();
	for( int i = 1 ; i <= n ; i++ ) a[i] = re();
	
	sort( a + 1 , a + n + 1 );
	for( int i = 1 ; i <= n ; i++ ) sum[i] = sum[ i - 1 ] + a[i];
	
	//排序
	for( int i = 1 ; i <= n ; i++ ){//每次假设这一个位置是最后一个，再二分
	 
		int l = 1 , r = i;
		while( l < r ){
			int mid = ( l + r ) >> 1;
			ll all = a[i] * ( i - mid + 1 ) , dif = sum[ i ] - sum[ mid - 1 ];
			
//			printf( " %d %d %d %d %d\n" , i , a[i] , l , r , all - dif );
			if( all - dif <= m )
				r = mid ;
			else l = mid + 1 ;
		}
		ans = max( ans , 1ll * i - r + 1 );
//		printf( "\n" );
	}
	printf( "%lld" , ans );
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

315275
313324
*/
