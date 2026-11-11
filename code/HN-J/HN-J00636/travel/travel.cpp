#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
//#define int long long
using namespace std;
const int N = 0;
string c1, s1, c2, s2;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	qwq;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] and s1[1] == s2[1]) {
			cout << 1;
			char a = s1[2], b = s2[2];
			if (('A' <= a and a <= 'C' and 'A' <= b and b <= 'C') or ('D' <= a and a <= 'F' and 'D' <= b and b <= 'F')) {
				cout << 1;
				if (a == b + 1 or a == b - 1) 
					cout << 1;
				else 
					cout << 0;
			}
			else 
				cout << "00";
		}
		else 
			cout << "000";
	}
	else 
		cout << "0000";
	return 0;
} 
