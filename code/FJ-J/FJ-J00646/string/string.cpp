#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;
long long n, t = 0, ans = 0;
char s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		long long a;
		char c;
		cin >> a >> c;
		for (long long j = 1; j <= a; j++) {
			t++;
			s[t] = c;
		}
	}
	long long mid = t / 2;
	for (long long i = 1 ; i <= mid; i++) {
		if (s[i] != s[t + 1 - i]) ans ++;
	}
	cout << ans;
	return 0;
}
