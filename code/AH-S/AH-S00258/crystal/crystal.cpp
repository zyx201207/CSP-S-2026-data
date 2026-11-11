#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, k;
long long a[5000010], cnt = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	long long mid = n / 2 + 1;
	long long x = a[mid], y = 0;
	for (long long i = 1; i <= mid; i++) {
		y += x - a[i];
		a[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		if (y <= m) {
			if (a[i] == a[i + 1]) cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
