#include<bits/stdc++.h>
using namespace std ;
int a [ 212345 ] ;
int main ( ) {
	freopen ( "card.in" , "r" , stdin ) ;
	freopen ( "card.out" , "w" , stdout ) ;
	int n , m ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++ ) {
		cout << n - i + 1 << " " ;
	}
	return 0 ; 
}
