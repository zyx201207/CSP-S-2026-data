#include<bits/stdc++.h>
using namespace std ;
char c[10] , s[10] , x[10] , y[10] ;

int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin >> c >> x >> s >> y ;
	bool f = ( c[0] == s[0] && c[1] == s[1] ) ;
	cout << f ;
	bool k = ( x[0] == y[0] && x[1] == y[1] ) && f ;
	cout << k ;
	bool v = ( x[2] > 'C' && y[2] > 'C' ) || ( y[2] <= 'C' && x[2] <= 'C' ) && k ;
	cout << v ;
	if( v && ( x[2] + 1 == y[2] || y[2] + 1 == x[2] ) )   cout << 1 ;
	else  cout << 0 ;
	return 0 ;
} 
