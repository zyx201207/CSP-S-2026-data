#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string a1, b1, a2, b2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= 'A' && s1[i] <= 'F') {
			a2 += s1[i];
			break;
		}
		a1 += s1[i];
	}
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= 'A' && s2[i] <= 'F') {
			b2 += s2[i];
			break;
		}
		b1 += s2[i];
	}
	if (c1 == c2) {
		cout << 1;
		if (a1 == b1) {
			cout << 1;
			if ((a2 <= "C" && b2 <= "C") || (a2 >= "D" && b2 >= "D")) {
				cout << 1;
				if (a2 >= "D" && b2 >= "D") {
					cout << 1;
				}else if (a2 == "C" && b2 == "B") {
					cout << 1;
				}else if (a2 == "B" && b2 == "A") {
					cout << 1;
				}else if (a2 == "B" && b2 == "C") {
					cout << 1;
				}else if (a2 == "A" && b2 == "B") {
					cout << 1;
				}else {
					cout << 0;
				}
			}else cout << 0 << 0;
		}else cout << 0 << 0 << 0;
	}else cout << 0 << 0 << 0 << 0;
	return 0;
}
