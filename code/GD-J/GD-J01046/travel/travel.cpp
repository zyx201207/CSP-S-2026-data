#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 1e5 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if (s1[2] <= 'C' && s2[2] <= 'C') {
				cout << "1";
				if ((s1[2] + 1 == s2[2]) || (s2[2] + 1 == s1[2])) {
					cout << "1" << '\n';
				}
				else
					cout << "0" << '\n';
			}
			else if (s1[2] >= 'D' && s2[2] >= 'D') {
				cout << "11" << '\n';
			}
			else
				cout << "00" << '\n';
		}
		else
			cout << "000" << '\n';
	}
	else
		cout << "0000" << '\n';
	
	return 0;
}
