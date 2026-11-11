#include<bits/stdc++.h>
using namespace std ;
int n ;
long long c ;
long long a[200010] ;
char s[100010] ;

int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] >> s[i] ;
	}
	long long h ;
	long long x = 1 , y = 1 ;
	long long f = n , k = a[n] ; 
	while( x < f ){
		if( s[x] != s[f] ){
			h = min( k , a[x] - y + 1 ) ;
			k -= h ;	y += h ;
			if( k < 1 ){
				f-- ;
				k = a[f] + k ;
			}
			if( y > a[x] ){
				x++ ;
				y -= a[x-1] ;
			}
			c += h ;
		}
		else{
			h = min( k , a[x] - y + 1 ) ;
			k -= h ;  y += h ;
			if( k < 1 ){
				f-- ;
				k += a[f] ;
			}
			if( y > a[x] ){
				x++ ;
				y -= a[x-1] ;
			}
		}
	}
	cout << c % 7395773051188020225 ;
	return 0 ;
} 
