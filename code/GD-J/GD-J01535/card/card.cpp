#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5 , M = 3e5 + 5 ;
int n , m ;
int a[N] , f[M] , cf[N] , ans[M];
bool flag[M];
map<int,int> mp;
int main() {
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout );
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i];
		if ( mp[a[i]] ) f[a[i]] = i;
		mp[a[i]] ++ ;
	}
	for ( int i = 1 ; i <= n ; i ++ ){
		for ( int j = i ; j <= n ; ) {
			while ( !f[a[j]] && j <= n ) {
				j ++ ;
			}
			if ( !f[a[j]] ) break;
			cf[j] -- , cf[f[a[j]]] ++ ;
			j = f[a[j]] + 1;
		}
	}
	for ( int i = 1; i <= n ; i ++ ) cf[i] += cf[i - 1] ;
	for ( int i = 1; i <= n ; i ++ ) {
		ans[a[i]] = max ( ans[a[i]] , i + cf[i]);
	}
	for ( int i = 1 ; i <= m ; i ++ ) cout << ans[i] << " ";
	return 0;
}

