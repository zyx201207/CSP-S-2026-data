#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005;
int a[N];
char c[N];

void solve() {
	int n;
	cin >> n;
	
	string s;
	int T = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		s += string(a[i], c[i]);
		T += a[i];
	}
	
	if (T <= 100000000) {
		int cnt = 0;
		for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
			if (s[i] != s[j]) ++cnt;
		}
		
		cout << cnt << '\n';
	} else {
		cout << T / 2 << '\n';
	}
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
