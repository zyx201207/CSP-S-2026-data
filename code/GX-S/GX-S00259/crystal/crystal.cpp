#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], ans;
int main(){
	freopen( "crystal.in", "r", stdin );
	freopen( "crystal.out", "w", stdout );
	cin >> n >> m;
	for ( int i = 1; i <= n; i++) cin >> a[i];
	sort( a + 1, a + n + 1 );
	ll s = 0;
	for ( int i = 1, j = 1; i <= n; i++){
		s += ( a[i] - a[i - 1] ) * ( i - j );
		while ( s > m ){
			s -= a[i] - a[j];
			j++;
		}
		ans = max( ans, ll( i - j + 1 ) );
	}
	cout << ans;
	return 0;
}
