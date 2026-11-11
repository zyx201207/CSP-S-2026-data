#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
string t1, s1, t2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> t1  >> s1 >> t2 >> s2;
	if (t1 == t2) {
		if (s1[1] == s2[1]) {
			if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' ||
				s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F') {
				if (abs(s1[2] - s2[2]) == 1) cout << "1111" << endl;
				else cout << "1110" << endl;
			} else cout << "1100" << endl;
		} else cout << "1000" << endl;
	} else cout << "0000" << endl;
	return 0;
}

