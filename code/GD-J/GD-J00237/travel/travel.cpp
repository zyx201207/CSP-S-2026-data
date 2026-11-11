#include <bits/stdc++.h>
using namespace std;
string aa, ab, ba, bb;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> aa >> ab >> ba >> bb;
	if (aa == ba) {
		cout << 1;
		string st = ab.substr (0, 2), str = bb.substr (0, 2);
		if (st == str) {
			cout << 1;
			int bta, btb;
			if (ab[2] == 'D' || ab[2] == 'F') bta = 2;
			else bta = 1;
			if (bb[2] == 'D' || bb[2] == 'F') btb = 2;
			else btb = 1;
			if (bta == btb) {
				cout << 1;
				if (bta == 2) cout << 1;
				else if (abs ((int) (ab[2]) - (int) (bb[2])) == 1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		} else cout << "000";
	} else {
		cout << "0000";
	}
	return 0;
}
//100pts
