#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5;
string s;
long long l = 0, a[MAX_N], cnt = 0, b = 1;
char c[MAX_N];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		l += a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s[b] = c[i];
			b++;
		}
	}
	for (int i = 1; i <= l; i++) {
		if (s[i] != s[l-i+1]) {
			s[l-i+1] = s[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

