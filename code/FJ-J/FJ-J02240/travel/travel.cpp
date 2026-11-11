#include <iostream>
using namespace std;

int main() {

	int c1, c2;
	string s1, s2;

	cin >> c1 >> s1[1] >> s1[2] >> s1[3] >> c2 >> s2[1] >> s2[2] >> s2[3];
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[3] == 'A' && s2[3] == 'B') or (s1[3] == 'A' && s2[3] == 'C') or (s1[3] == 'B' && s2[3] == 'A') or (s1[3] == 'B' && s2[3] == 'C') or (s1[3] == 'C' && s2[3] == 'A') or (s1[3] == 'C' && s2[3] == 'B') or (s1[3] == 'D' && s2[3] == 'F') or (s1[3] == 'F' && s2[3] == 'D')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if ((s1[3] == 'A' && s2[3] == 'B') or (s1[3] == 'B' && s2[3] == 'A') or (s1[3] == 'B' && s2[3] == 'C') or (s1[3] == 'C' && s2[3] == 'B') or (s1[3] == 'D' && s2[3] == 'F') or (s1[3] == 'F' && s2[3] == 'D')) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}
