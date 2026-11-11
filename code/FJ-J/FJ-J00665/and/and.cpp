#include<bits/stdc++.h>
using namespace std ;
int n , m ;
long long a[200010] ;
long long maxx = -1 ;

int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	if( m == 1 ){
		for( int i = 1 ; i <= n ; i++ ){
			maxx = max( a[i] , maxx ) ;
		}
		cout << maxx ;
	}
	else{
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = i ; j <= n ; j++ ){
				long long v = a[i] ;
				long long g = a[j] ;
				long long f = v & g ;
				maxx = max( f , maxx ) ;
			}
		}
		cout << maxx ;
	}
	return 0 ;
} 
