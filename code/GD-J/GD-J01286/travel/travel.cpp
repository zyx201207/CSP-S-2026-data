#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		cout << '1';
		if (s2.substr(0, 2) == s4.substr(0, 2)) {
			cout << '1';
			if ((s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] > 'C' && s4[2] > 'C')) {
				cout << '1';
				if (abs(s2[2] - s4[2]) == 1) cout << '1';
				else cout << '0';
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	
	cout << '\n';
	return 0;
}
