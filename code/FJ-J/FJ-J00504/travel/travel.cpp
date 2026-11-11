#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a == c) cout << 1;
	else {
		cout << "0000" << endl;
		return 0;
	}
	string sx = "", sy = "";
	sx += b[0];
	sx += b[1];
	sy += d[0];
	sy += d[1];
	if((a == c) && (sx == sy)) cout << 1;
	else {
		cout << "000" << endl;
		return 0;
	}
	sx = b[2], sy = d[2];
	char ca = sx[0], cb = sy[0];
	if((ca == 'A' && cb == 'B') || (ca == 'A' && cb == 'C') || (ca == 'B' && cb == 'C')) {
		cout << 1;
	}
	else if((ca == 'B' && cb == 'A') || (ca == 'C' && cb == 'A') || (cb == 'B' && ca == 'C')) {
		cout << 1;
	}
	else if((ca == 'D' && cb == 'F') || (ca == 'F' && cb == 'D')) cout << 1;
	else {
		cout << "00" << endl;
		return 0;
	}
	if((ca == 'A' && cb == 'B') || (ca == 'B' && cb == 'A') || (ca == 'B' && cb == 'C')) {
		cout << 1;
	}
	else if((cb == 'B' && ca == 'C') || (ca == 'D' && cb == 'F') || (ca == 'F' && cb == 'D')) {
		cout << 1;
	}
	else cout << 0;
	return 0;
}
