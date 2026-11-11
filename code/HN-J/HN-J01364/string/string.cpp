#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;
using ll = long long;

int constexpr N = 2e5 + 5;
ll a_[ N ];
char c_[ N ];
struct Segment { ll a; char c; };
int main() {
	freopen( "string.in", "r", stdin );
	freopen( "string.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	int n; cin >> n;
	if ( n == 1 ) { cout << "0\n"; return 0; }
	for ( int i = 1; i <= n; ++i ) { cin >> a_[ i ] >> c_[ i ]; }
	deque<Segment> segments;
	int l = 1, r = 1;
	while ( l <= n && r <= n ) {
		ll sum = 0;
		while ( r <= n && c_[ r ] == c_[ l ] ) { sum += a_[ r++ ]; }
		segments.push_back( { sum, c_[ l ] } );
		l = r;
	}
	ll ans = 0;
	while ( ( int ) segments.size() > 1 ) {
		Segment front = segments.front(),
				back = segments.back();
		ll diff = front.a - back.a;
		segments.pop_front();
		segments.pop_back();
		if ( front.c == back.c ) {
			if ( !diff ) { continue; }
			if ( diff > 0 ) { segments.push_front( { diff, front.c } ); }
			else { segments.push_back( { -diff, front.c } ); }
		} else {
			if ( !diff ) { ans += front.a; continue; }
			if ( diff > 0 ) {
				ans += back.a;
				segments.push_front( { diff, front.c } );
			} else {
				ans += front.a;
				segments.push_back( { -diff, back.c } );
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

