#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, ans, m;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		char c;
		cin >> x >> c;
		m += x;
		while (x--) {
			s += c;
		}
	}
	for (int i = 0; i < m / 2; i++) {
		ans += (s[i] != s[m - i - 1]);
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c
2

2
2 a
3 a
0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
3000000000

4
1 a
1 s
1 a
3 d
3
*/

