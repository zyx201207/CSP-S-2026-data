#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m , a[N] , ans ;
bool check ( int k ) {
	int sum = 0;
	for ( int i = 1; i <= n ; i ++ ) {
		if ( a[i] & ( 1 << k ) ) sum ++ ;
	}
	return sum >= m ;
}
int main() {
	freopen("and.in" , "r" , stdin );
	freopen("and.out" , "w" , stdout );
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i];
	int cnt = 0 , ans = INT_MAX;
	while ( 1 )  {
		int r = min ( ans , 31) - 1;
		ans = -1;
		for ( int i = 0 ; i <= r ; i ++ ) {
			if ( check(i) ) ans = i ;
		}
		if ( ans == -1 ) break;
		int op = 0 ;
		for ( int i = 1; i <= n ; i ++ ) {
			if ( a[i] & ( 1 << ans ) ) {
				a[++op] = a[i];
			}
		}
		n = op;
		cnt |= (1 << ans);
	}
	cout << cnt ;
	return 0;
}
