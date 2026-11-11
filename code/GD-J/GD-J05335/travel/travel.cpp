#include <iostream>
#include <cstdio>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000" << endl;
	} else if(s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "1000" << endl;
	} else if(('A' <= s1[2] && s1[2] <= 'C' && 'D' <= s2[2] && s2[2] <= 'F') || ('A' <= s2[2] && s2[2] <= 'C' && 'D' <= s1[2] && s1[2] <= 'F')) {
		cout << "1100" << endl;
	} else if(('A' <= s1[2] && s1[2] < 'C' && (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])) || (s1[2] == 'C' && s2[2] == 'B') || ('D' == s1[2] && 'F' == s2[2]) || ('D' == s2[2] && 'F' == s1[2])) {
		cout << "1111" << endl;
	} else {
		cout << "1110" << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
