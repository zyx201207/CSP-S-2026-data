#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[6], k = 0;
	cin >> n >> m;
	for (int i = 1; i <+ n; i ++) {
		cin >> a[i];
		if (a[i] == 1) k ++;
	}
	if (a[n] == 1 && a[1] == 1) {
		cout << n << ' ' << '0';
	}
	if (a[n] == 1 && a[1] == 2) {
		cout << n << ' ' << k;
	}
	if (a[n] == 2 && a[1] == 1) {
		cout << '0' << ' ' << n;
	}
	if (a[n] == 2 && a[1] == 2) {
		cout << k << ' ' << n;
	}
	return 0;
}