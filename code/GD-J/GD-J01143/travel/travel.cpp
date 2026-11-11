#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2) cout << "0000\n";
	else if (s1.substr(0, 2) != s2.substr(0, 2)) cout << "1000\n";
	else if ((s1[2] < 'D') != (s2[2] < 'D')) cout << "1100\n";
	else if (abs(s1[2] - s2[2]) != 1) cout << "1110\n";
	else cout << "1111\n";
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
