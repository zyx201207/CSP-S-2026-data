#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] != c2[0] || c1[1] != c2[1]) {
		cout << "0000" << endl;
		return 0;
	}
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "1000" << endl;
		return 0;
	}
	char a = s1[2],b = s2[2];
	bool f = 0;
	if ((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C')) f = 1;
	if ((a == 'D' || a == 'F') && (b == 'D' || b == 'F')) f = 1;
	if (!f) {
		cout << "1100" << endl;
		return 0;
	}
	f = 0;
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) f = 1;
	if ((a == 'B' && b == 'A') || (a == 'C' && b == 'B') || (a == 'F' && b == 'D')) f = 1; 
	if (!f) cout << "1110" << endl;
	else cout << "1111" << endl;
	return 0;
}
