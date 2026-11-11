#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2) {
		cout << "0000\n";
	} else {
		if (s1.substr(0, 2) != s2.substr(0, 2)) {
			cout << "1000\n";
		} else {
			if (('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'E' && 'D' <= s2[2] && s2[2] <= 'E')) {
				if (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1) {
					cout << "1111\n";
				} else {
					cout << "1110\n";
				}
			} else {
				cout << "1100\n";
			}
		}
	}
	
	return 0;
}
