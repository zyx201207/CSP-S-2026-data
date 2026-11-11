#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000\n";
	} else if (s1.substr(0, 2) != s2.substr(0, 2)) {
		cout << "1000\n";
	} else if ((s1[2] <= 'C') ^ (s2[2] <= 'C')) {
		cout << "1100\n";
	} else if (min(s1[2], s2[2]) == 'A' && max(s1[2], s2[2]) == 'C') {
		cout << "1110\n";
	} else {
		cout << "1111\n";
	}
	
//	cerr << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

/*
\zrr/\zrr/\zrr/ 
*/
