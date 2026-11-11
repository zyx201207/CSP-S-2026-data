#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 5 ;
long long n , a[N] ;
long long cnt ;
char c[N] ;
string s ;
int main(){
	freopen( "string.in" , "r" , stdin ) ;
	freopen( "string.out" , "w" , stdout ) ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] >> c[i] ;
		s += string( a[i] , c[i] ) ;
	}
	for( int i = 0 ; i < s.size() / 2 ; i++ ){
		if( s[i] != s[s.size() - i - 1] ){
			cnt++ ;
		}
	}
	cout << cnt ;
	return 0 ;
}
