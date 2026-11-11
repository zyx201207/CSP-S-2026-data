// lichenxi108.rp = inf, JCer.rp = -inf;
// 也许这是最后一战了。I won't AFO.
// 我该在哪里停留？我问我自己。

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	string s1, t1, s2, t2;
	cin >> s1 >> t1 >> s2 >> t2;
	if (s1 != s2) {
		cout << "0000";
		return 0;
	}
	cout << '1';
	
	if (t1.substr(0, 2) != t2.substr(0, 2)) {
		cout << "000";
		return 0;
	}
	cout << '1';
	
	if ((t1[2] <= 'C' && t2[2] > 'C') || (t1[2] > 'C' && t2[2] <= 'C')) {
		cout << "00";
		return 0;
	}
	cout << '1';
	
	cout << ((t1[2] == 'B' && t2[2] <= 'C') || (t2[2] == 'B' && t1[2] <= 'C') || (t1[2] > 'C' && t2[2] > 'C'));
	return 0;
} 
