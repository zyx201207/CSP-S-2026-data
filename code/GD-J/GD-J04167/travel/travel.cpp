#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << "1";
		if (s1[0] != s2[0] || s1[1] != s2[1]) {
			cout << "000";
		} else {
			cout << "1";
			long long a = 0, b = 0;
			switch(s1[2]) {
				case 'A': case 'B': case 'C': a = 1; break;
				case 'D': case 'F': a = -1; break;
			}
			switch(s2[2]) {
				case 'A': case 'B': case 'C': b = 1; break;
				case 'D': case 'F': b = -1; break;
			}
			if (a != b) {
				cout << "00";
			} else {
				cout << "1";
				if (s1[2] == 'D' || s1[2] == 'F') cout << "1";
				else if (s1[2] == 'B' || s2[2] == 'B') cout << "1";
				else cout << "0";
			}
		}
	}
	return 0;
}
