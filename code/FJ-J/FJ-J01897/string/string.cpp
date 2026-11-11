#include <bits/stdc++.h>
using namespace std;
char a[200005];
long long w[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int c = 0;
		cin >> c;
		char s = 0;
		cin >> s;
		a[i] = s;
		w[i] = c;
	}
	long long l = 1, r = n, sum = 0;
	while (l < r) {
		if (a[l] == a[r]) {
			int j = min(w[l], w[r]);
			w[l] -= j;
			w[r] -= j;
		} else {
			int j = min(w[l], w[r]);
			sum += j;
			w[l] -= j;
			w[r] -= j;
		}
		if (w[l] == 0) l++;
		if (w[r] == 0) r--;
	}
	cout << sum;
	return 0;
}
