#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int c , t , n , d , a[N] ;
map<pair<int,int> , int > mp;
signed main() {
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout );
	cin >> c >> t;
	while ( t -- ) {
		cin >> n >> d ;
		for ( int i = 1; i <= n ; i ++ ) cin >> a[i];
		int sum = 0;
		for ( int i = 1; i <= n ; i ++ ) {
			for ( int j = i + 1; j <= n ; j ++ ) {
				if ( a[j] - a[i] <= d ) {
					for ( int k = 1 ; k < i ; k ++ ) {
						for ( int op = j + 1 ; op <= n ; op ++ ) {
							if ( a[j] - a[k] <= d && a[op] - a[i] <= d ) {
								if ( !mp[{k , op}] ) sum ++ ;
								mp[{k , op}] = 1;
							}
						}
					}
				}
			}
		}
		cout << sum << "\n" ;
	}
	return 0;
}
