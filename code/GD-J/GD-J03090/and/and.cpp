#include <bits/stdc++.h>
using namespace std ;
freopen( "and.in" , "r" , std.in )
freopen( "and.out" , "w" , std.out )
priority_queue< int > q ;
int main() {
	int n , m ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) {
		int v ;
		cin >> v ;
		q.push( v ) ;
	}
	for ( int i = 1 ; i < m ; i++ ) {
		q.pop() ;
	}
	cout << q.top() ;
	return 0 ;
}
