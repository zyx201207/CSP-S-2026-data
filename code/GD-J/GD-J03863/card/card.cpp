#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100 ;
int n , m ;
int a[N] ;
bool vis[N] ;
int f[N] ;
int main() {
	freopen( "card.in" , "r" , stdin ) , freopen( "card.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) , cin.tie(0) ;
	cin>>n>>m ;
	for( int i = 1 ; i <= n ; i++ ) cin>>a[i] ;
	for( int i = n ; i >= 1 ; i-- ) {
		bool flag = false ;
		if( f[a[i]] ) continue ;
		for( int j = 1 ; j < i ; j++ ) {
			for( int k = i + 1 ; k <= n ; k++ ) {
				if( a[j] == a[k] ) {
					f[a[i]] = i - ( j + 1 ) + 1 ;
					flag = true ;
					break ;
				} 
			}
		}
		if( !flag ) f[a[i]] = i ;
	}
	for( int i = 1 ; i <= m ; i++ ) cout<<f[i]<<" " ;
	return 0 ;
}
