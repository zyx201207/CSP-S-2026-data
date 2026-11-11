#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2; 
int main () {
	freopen ( "travel.in", "r", stdin );
	freopen ( "travel.out", "w", stdout );
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = (s1[0] - '0') * 10 + s1[1] - '0';
	int b = (s2[0] - '0') * 10 + s2[1] - '0';
	char c = s1[2], d = s2[2];
	bool flag = 0, flag_ = 0;
	if ( c1 == c2 ) {
		if ( a == b ) {
			if ( ( c == 'D' && d == 'F' ) || ( c == 'F' && d == 'D' ) )
				flag = 1;
			if ( ( c == 'A' && ( d== 'B' || d == 'C' ) ) || ( c == 'B' && ( d == 'A' || d == 'C') ) || ( c == 'C' && ( d == 'A' || d == 'B' ) ) )
				flag = 1;
		}
		if ( a == b ) {
			if ( ( c == 'D' && d == 'F' ) || ( c == 'F' && d == 'D' ) )
				flag_ = 1;
			if ( ( c == 'A' && ( d== 'B') ) || ( c == 'B' && ( d == 'A' || d == 'C') ) || ( c == 'C' && (d == 'B' ) ) )
				flag_ = 1;
		}
	}
	cout << ( c1 == c2 ) << ( a == b && c1 == c2 ) << flag << flag_;
	return 0;
}
