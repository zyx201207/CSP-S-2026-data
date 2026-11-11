#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, a, b;
int c, d;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000";
	else {
		cout << 1;
		a += s1[0];
		a += s1[1];
		b += s2[0];
		b += s2[1];
		if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
			c = 1;
		}
		else c = 2;
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
			d = 1;
		}
		else d = 2;
		if (a == b){
			cout << "1";
			if (c == d) {
				cout << "1";
				if (s1[2] == 'A' && s2[2] == 'C') cout << "0";
				else if(s1[2] == 'C' && s2[2] == 'A') cout << "0";
				else cout << "1";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	return 0;
}
