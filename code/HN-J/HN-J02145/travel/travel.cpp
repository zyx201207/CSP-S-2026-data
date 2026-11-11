#include <bits/stdc++.h>
using namespace std;

signed main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 != s3) {
		cout << "0000";
		return 0;
	}
	if (s2[1] != s4[1]) {
		cout << "1000";
		return 0;
	}
	if (s2[2] < 'D' && s4[2] >= 'D') {
		cout << "1100";
		return 0;
	}
	if (s4[2] < 'D' && s2[2] >= 'D') {
		cout << "1100";
		return 0;
	}
	if (max(s4[2], s2[2]) - 1 == min(s4[2], s2[2])) {
		cout << "1111";
		return 0;
	} else {
		cout << "1110";
	}
  return 0;
}

