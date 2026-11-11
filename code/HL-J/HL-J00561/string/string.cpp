#include <bits/stdc++.h>

using namespace std;

int a[200001];
char c[200001];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	long long cnt = 0;
	for (int l = 1, r = n; l < r; ) {
		if (a[l] <= a[r]) {
			if (c[l] != c[r]) {
				cnt += a[l];
			}
			a[r] -= a[l];
			a[l] = 0;
			l++;
		} else {
			if (c[l] != c[r]) {
				cnt += a[r];
			}
			a[l] -= a[r];
			a[r] = 0;
			r--;
		}
	}
	cout << cnt;
	return 0;
}
