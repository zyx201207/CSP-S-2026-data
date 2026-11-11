#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int c1, c2, s1, s2; char ch1, ch2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> ch1 >> c2 >> s2 >> ch2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		cout << 1;
		if (s1 == s2) {
			cout << 1;
			if ((ch1 <= 'C' && ch2 <= 'C')
			   || (ch1 >= 'D' && ch2 >= 'D')) {
				cout << 1;
				if (abs(ch1 - ch2) == 1) cout << 1;
				else cout << 0;
				return 0;
			}
			else {
				cout << "00";
				return 0;
			}
		} else {
			cout << "000";
			return 0;
		}
	}
    return 0;
} 
