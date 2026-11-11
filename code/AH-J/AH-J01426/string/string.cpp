#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bool bl;
typedef double db;
const ll N = 2e5 + 10;
ll n, l, r, idx_r, idx_l, ans;
bl fl;
struct Node {
	ll b;
	char a;
} s[ N ];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio( false );
	cin.tie( 0 ), cout.tie( 0 );
	cin >> n;
	for ( ll i = 1; i <= n; ++i ) {
		cin >> s[ i ].b >> s[ i ].a;
	} l = 1; r = n;
	while ( l < r ) {
		char la = s[ l ].a, ra = s[ r ].a;
		ll lb = s[ l ].b, rb = s[ r ].b;
		if ( lb < rb ) {
			s[ r ].b -= lb;
			ans += lb * ( la != ra );
			l += 1;
		} else if ( lb == rb ) {
			ans += lb * ( la != ra );
			l += 1; r -= 1;
		} else {
			s[ l ].b -= rb;
			ans += rb * ( la != ra );
			r -= 1;
		}
	} cout << ans;
	return 0;
}
