#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	bool ok1 = (s1[0] * 10 + s1[1] == s2[0] * 10 + s2[1]);
	int cnt = 0;
	if (ok1) cout << 1;
	else cout << 0;
	
	if (ok1) {
		if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
			cout << 1;
			cnt = 1;
		}
		else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
			cout << 1;
			cnt = 2;
		}
		else cout << 0;
	}
	else cout << 0;
	
	if (ok1 && cnt) {
		if (cnt == 1) {
			if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'C' && s1[2] == 'B')) {
				cout << 1;
			}
			else cout << 0;
		}
		if (cnt == 2) {
			if ((s1[2] == 'F' && s2[2] == 'D') || (s2[2] == 'F' && s1[2] == 'D')) {
				cout << 1;
			}
			else cout << 0;
		}
	}
	else cout << 0;
	return 0;
}
