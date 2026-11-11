#include <bits/stdc++.h>
using namespace std;


string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (s1[2] == 'F') s1[2] = 'E';
	if (s2[2] == 'F') s2[2] = 'E';
//	cout << c1 << " " << s1 << " " << c2 << " " << s2 << endl;
	if (c1 == c2) {
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			int a, b;
			a = (s1[2] == 'D' || s1[2] == 'E');
			b = (s2[2] == 'D' || s2[2] == 'E');
			if (a == b) {
				if (abs(s1[2] - s2[2]) == 1) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000"; 
	}
	return 0;
} 
