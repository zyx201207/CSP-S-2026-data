#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;

int main () {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000" << endl;
	else {
		cout << "1";
		if (s1[0] != s2[0] || s1[1] != s2[1]) cout << "000" << endl;
		else {
			cout << "1";
			char x = s1[2], y = s2[2];
			if ((x <= 'C' && y <= 'C') || (x >= 'D' && y >= 'D')) {
				cout << "1";
				if ((x == 'A' && y == 'B') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')) cout << "1";
				else cout << "0";	
			} else cout << "00";
		}
	}
	
	return 0;
}
