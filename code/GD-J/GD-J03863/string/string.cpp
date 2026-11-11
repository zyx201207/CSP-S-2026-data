#include<bits/stdc++.h>
#define ll long long 
using namespace std ;
const int N = 2e5 + 100 ;
int n ;
ll answer ;
struct node {
	int num ; 
	string s ;
}a[N] ;
int main() {
	freopen( "string.in" , "r" , stdin ) , freopen( "string.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) , cin.tie(0) ;
	cin>>n ;
	for( int i = 1 ; i <= n ; i++ ) cin>>a[i].num>>a[i].s ;
	int l = 1  , r = n ;
	while( l < r ) {
		if( a[l].num == a[r].num ) { if( a[l].s != a[r].s ) answer += a[l].num ; l++ , r-- ; }
		else {
			while( l < r && a[l].num != a[r].num ) {
				if( a[l].num > a[r].num ) {
					if( a[l].s != a[r].s ) answer += a[r].num ;
					a[l].num -= a[r].num ;
					r-- ;
				}else {
					if( a[l].s != a[r].s ) answer += a[l].num ;
					a[r].num -= a[l].num ;
					l++ ;
				}
			}
		}
	}
	cout<<answer ;
	return 0 ; 
}
