#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 5 ;
const int M = 3e5 + 5 ;
int n , m , a[N] , b[N] , last_id[M] , d[M] ;
int main(){
	freopen( "card.in" , "r" , stdin ) ;
	freopen( "card.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	for( int i = 1 ; i <= n ; i++ ){
		int id = 0 ;
		memset( last_id , 0 , sizeof(last_id) ) ;
		for( int j = i ; j <= n ; j++ ){
			if( last_id[a[j]] == 0 ){
				b[++id] = a[j] ;
				last_id[a[j]] = id ;
			}else{
				int ls = id ;
				id = last_id[a[j]] ;
				for( int x = id + 1 ; x <= ls ; x++ ){
					last_id[a[x]] = 0 ;
				}
			}
		}
		for( int j = 1 ; j <= id ; j++ ){
			d[b[j]]++ ;
		}
	}
	for( int i = 1 ; i <= m ; i++ ){
		cout << d[i] << " " ;
	}
	return 0 ;
}
