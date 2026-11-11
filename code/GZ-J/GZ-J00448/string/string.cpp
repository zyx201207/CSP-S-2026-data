//GZ-J00448 КывужабЇ СѕуфУњ 
#include <bits/stdc++.h>
using namespace std;

unsigned long long n, ans, few, a[200010];
char c[200010];
string s, r;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (unsigned long long t = 1; t <= n; t++)
		cin >> a[t] >> c[t];
	for (unsigned long long t = 1; t <= n; t++) {
		for (unsigned long long i = 1; i <= a[t]; i++)
			s += c[t];
	}
	for (unsigned long long t = n; t >= 1; t--) {
		for (unsigned long long i = 1; i <= a[t]; i++)
			r += c[t];
	}
	
	for (unsigned long long i = 1; i <= n; i++) {
		if (s[i] != r[i]) ans++;
	}
	
	cout << ans / 2 << "\n";
	
	return 0;
}
