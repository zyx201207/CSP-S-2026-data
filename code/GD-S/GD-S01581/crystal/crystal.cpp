#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n , k , ans , maxx , a[N] , s[N];
signed main() {
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout );
	cin >> n >> k ;
	for ( int i = 1; i <= n ; i ++ ) cin >> a[i];
	sort (a + 1 , a + n + 1 );
	for ( int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + a[i];
	for ( int i = 1; i <= n ; i ++ ) {
		int l = 1 , r = i , ans = 0;
		while ( l <= r ) {
			int mid = (l + r) >> 1;
			if ( a[i] * ( i - mid + 1) - (s[i] - s[mid - 1]) <= k ) {
				r = mid - 1 , ans = mid;
			} else l = mid + 1;
		}
		maxx = max ( maxx , i - ans + 1);
	}
	cout << maxx ;
	return 0;
}
