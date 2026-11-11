#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	vector<pair<int, char> > s(n);
	for(int i = 0; i < n; i++) {
		int _a;
		char _c;
		cin >> _a >> _c;
		s[i].first = _a, s[i].second = _c;
	}
	long long ans = 0;
	int l = 0, r = n - 1;
	while(l < r) {
		int mina = min(s[l].first, s[r].first);
		if (s[l].second != s[r].second) {
			ans += mina;
		}
		s[l].first -= mina, s[r].first -= mina;
		if (!s[l].first) l++;
		if (!s[r].first) r--;
	}
	cout << ans << '\n';
	return 0;
} 
