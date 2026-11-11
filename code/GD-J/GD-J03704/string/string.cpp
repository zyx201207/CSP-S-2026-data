#include <bits/stdc++.h>
using namespace std;

int n, a, c, l, cnt;
vector<char> s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	s.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		l += a;
		for (int j = 1; j <= a; j++)
			s.push_back(c);
	}
	for (int i = 1; i <= (l / 2); i++)
		if (s[i] != s[l + 1 - i])
			cnt++;
	cout << cnt;
	return 0;
}
