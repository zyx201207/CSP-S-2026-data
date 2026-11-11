#include <bits/stdc++.h>

using namespace std;

long long n, sum = 0;
long long a[200001];
char c[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> c[i];
	}
	long long l = 0, r = n - 1;
	while (l <= r) {
		if (c[l] == c[r]) {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				a[r] = 0;
				-- r;
			}
			else if (a[l] < a[r]) {
				a[r] -= a[l];
				a[l] = 0;
				++ l;
			}
			else {
				a[l] = a[r] = 0;
				++ l;
				-- r;
			}
		}
		else {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				sum += a[r];
				a[r] = 0;
				-- r;
			}
			else if (a[l] <= a[r]) {
				a[r] -= a[l];
				sum += a[l];
				a[l] = 0;
				++ l;
			}
			else {
				a[l] = a[r] = 0;
				sum += a[l];
				++ l;
				-- r;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
