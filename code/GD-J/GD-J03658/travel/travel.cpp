#include <bits/stdc++.h>
using namespace std;
#define int long long

string a, b, c, d; 

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			if (!((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'D' || d[2] == 'F')) && !((d[2] == 'A' || d[2] == 'B' || d[2] == 'C') && (b[2] == 'D' || b[2] == 'F'))) {
				cout << "1";
				if ((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D') || (b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'B')) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
/*
02 01A 02 01B

02 01C 02 01A

02 01C 02 01D

02 02B 02 01A

02 01A 03 01A
*/
