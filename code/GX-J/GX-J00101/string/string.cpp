#include <bits/stdc++.h>
using namespace std;

long long n, len, ans, step = -1, a[200001];
char c[200001];

char index(long long w) {
	for (long long i = 1; i <= n; i++) 
		if (a[i] >= w && a[i - 1] <= w) return c[i];
	return '\0';
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i]; a[i] += a[i - 1];
	}
	step = a[1];
	for (int i = 2; i <= n; i++) step = gcd(step, a[i]);
	for (long long i = 1, j = len; i <= j; i += step, j -= step)
		if (index(i) != index(j)) ans++;
	cout << ans * step << endl;
	return 0;
}