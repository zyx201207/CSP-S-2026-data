#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n, ans = 0;
string s;
struct emm {
	ll t;
	char c;
} a[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t >> a[i].c;
		for (int j = 1; j <= a[i].t; j++) {
			s += a[i].c;
		}
	}
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		if (i >= sz-i-1) break;
		if (s[i] != s[sz-i-1]) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
