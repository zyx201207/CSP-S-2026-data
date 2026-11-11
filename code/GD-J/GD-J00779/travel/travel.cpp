#include<bits/stdc++.h>
#define int long long
#define vec vector
#define f(i, l, r) for (int (i) = (l); (i) <= (r); (i) ++)
using namespace std;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	int a = s1[2] - 'A', b = s2[2] - 'A';
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
		if (a < 3 && b < 3) cout << 1;
		else if (a >= 3 && b >= 3) cout << 1;
		else cout << 0;
		if (abs(a - b) == 1) cout << 1;
		else cout << 0;
//		if ((s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')) || (s1[2] == 'B' && (s2[2] == 'A') || s2[2] == 'C') || (s1[2] == 'C' && (s2[2] == 'A' || s2[2] == 'C')) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
//			cout << 1;
//		}  else {
//			cout << 0;
//		}
	}
	return 0;
} 
