#include <bits/stdc++.h>
// #define int long long
using namespace std;
string c1, s1, c2, s2;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>> c1 >> s1 >> c2 >> s2;
	int row1 = (s1[0] - '0') * 10 + s1[1] - '0', col1 = s1[2] - 'A';
	int row2 = (s2[0] - '0') * 10 + s2[1] - '0', col2 = s2[2] - 'A';
	if(col1 == 5) col1 = 4;
	if(col2 == 5) col2 = 4;
	if(c1 != c2) {
		cout << "0000\n";
	}
	else if(row1 != row2) {
		cout << "1000\n";
	}
	else if((col1 <= 2) ^ (col2 <= 2)) {
		cout << "1100\n";
	}
	else if(abs(col1 - col2) != 1) {
		cout << "1110\n";
	}
	else {
		cout << "1111\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
