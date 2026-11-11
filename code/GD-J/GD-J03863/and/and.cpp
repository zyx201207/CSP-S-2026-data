#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100 ;
int n , m ;
struct node{ int num , ones ; }a[N] ;
int answer ;
inline int solve_getone( int x ) {
	int tot = 0 ;
	while( x ) tot += ( x & 1 ) , x >>= 1 ;
	return tot ;
}
bool cmp( node x , node y ) { return ( x.ones == y.ones ) ? ( x.num > y.num ) : ( x.ones > y.ones ) ; }
int main() {
	freopen( "and.in" , "r" , stdin ) , freopen( "and.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) , cin.tie(0) ;
	cin>>n>>m ;
	for( int i = 1 ; i <= n ; i++ ) cin>>a[i].num , a[i].ones = solve_getone( a[i].num ) ;
	sort( a + 1 , a + n + 1 , cmp ) ;
	answer = a[1].num ;
	for( int i = 2 ; i <= m ; i++ ) answer &= a[i].num ;
	cout<<answer ;
	return 0 ;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100 ;
int n , m , answer ;
int a[N] , f[N][35] ;
vector<int>g[35] ;
inline void solve( int x , int idx ) {
	string s = "" ;
	while( x ) {
		s = (char)('0' + ( x & 1 ) ) + s ;
		x >>= 1 ;
	}
	int myidx = 0  ;
	for( int i = 0 ; i < s.size() ; i++ ) {
		if( s[i] == '1' ) {
			int k = s.size()-i-1 ;
			f[idx][k]++ , f[0][k]++ ;
			g[k].push_back( idx ) ;
		}
	}
	return ;
}
int main() {
	freopen( "and5.in" , "r" , stdin ) ; // , freopen( "and.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) , cin.tie(0) ;
	cin>>n>>m ;
	for( int i = 1 ; i <= n ; i++ ) cin>>a[i] , solve( a[i] , i ) ;
	for( int i = 32 ; i >= 0 ; i-- ) {
		if( f[0][i] >= m ) {
			answer = a[g[i][0]] ;
			for( int j = 1 ; j < m ; j++ ) answer &= a[g[i][j]] ;
			cout<<answer ;
			return 0 ;
		}
	}
	return 0 ;
}*/
