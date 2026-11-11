//GZ-J00667 遵义市第十二中学 陈俊熙
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long a[N];
char c[N];
int n;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		for (long long j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}

	int ans = 0;
	for (long long i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			ans++;
		}
	}

	cout << ans;
	return 0;
}
