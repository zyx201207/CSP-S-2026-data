#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	unsigned long long n, a, ans = 0;
	string s, c;
	cin >> n;
	for (unsigned long long i = 1; i <= n; i++) {
		cin >> a >> c;
		for (unsigned long long i = 1; i <= a; i++) s += c;
		unsigned long long len = s.size();
		for (unsigned long long i = 0; i < len / 2; i++) {
			if (s[i] != s[len - i]) {
				ans++;
				s[i] = s[len - i];
			}
		}
	}
	cout << ans;
	return 0;
}
