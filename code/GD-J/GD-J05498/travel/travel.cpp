#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
string c1, s1, c2, s2;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> c1 >> s1 >> c2 >> s2;
	string p1 = s1.substr(0, 2);
	string p2 = s2.substr(0, 2);
	char pos1 = s1[2], pos2 = s2[2];
	bool a1 = (c1 == c2);
	bool a2 = a1 & (p1 == p2);
	bool a3 = a2 & ((pos1 <= 'C') ^ (pos2 > 'C'));
	bool a4 = a3 & (abs(pos2 - pos1) == 1);
	cout << a1 << a2 << a3 << a4 << endl;
	return 0;
}
