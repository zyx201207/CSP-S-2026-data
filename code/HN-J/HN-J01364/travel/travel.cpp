#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	freopen( "travel.in", "r", stdin );
	freopen( "travel.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	int c1, c2, s1n, s2n;
	char r1, r2;
	cin >> c1 >> s1n >> r1
		>> c2 >> s2n >> r2;
	if ( c1 != c2 ) { cout << "0000\n"; return 0; }
	cout << '1';
	if ( s1n != s2n ) { cout << "000\n"; return 0; }
	cout << '1';
	if ( !( r1 <= 'C' && r2 <= 'C' ) &&
	     !( r1 >= 'D' && r2 >= 'D' ) )
	{ cout << "00\n"; return 0; }
	cout << '1'
		 << ( r1 + 1 == r2 || r2 + 1 == r1 ||
		 	( r1 == 'D' && r2 == 'F' ) || ( r1 == 'F' && r2 == 'D' ) ) 
		 << '\n';
	return 0;
}

