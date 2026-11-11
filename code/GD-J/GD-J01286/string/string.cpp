#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
const int N = 2e5 + 5;
struct str {
	int num;
	char ch;
	void putin() {
		cin >> num >> ch;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	str s[N];
	for (int i = 1; i <= n; ++i) {
		s[i].putin();
	}
	
	int l = 1, r = n;
	LL ans = 0LL;
	while (l < r) {
		if (s[l].ch == s[r].ch) {
			if (s[l].num == s[r].num) ++l, --r;
			else if (s[l].num > s[r].num) s[l].num -= s[r].num, --r;
			else s[r].num -= s[l].num, ++l;
		} else {
			if (s[l].num == s[r].num) ans += s[l].num, ++l, --r;
			else if (s[l].num > s[r].num) s[l].num -= s[r].num, ans += s[r].num, --r;
			else s[r].num -= s[l].num, ans += s[l].num, ++l;
		}
	}
	cout << ans << '\n';
	return 0;
}

