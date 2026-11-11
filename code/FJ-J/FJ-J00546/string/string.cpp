#include<bits/stdc++.h>
using namespace std;
long long n, ans = 0, a, num;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 0; i < n; i++) {
		char c;
		cin >> a >> c;
		string f(a, c);
		s += f;
	}
	num = s.size();
	for (long long i = 0; i < num; i++) {
		ans += s[i] != s[num - i - 1] ? 1 : 0;
	}
	cout << ans / 2;
	return 0;
}
