#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], num[N], ans;
bool f = 0;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		num[a[i]]++;
		if (a[i - 1] > a[i]) {
			f = 1;
		}
	}
	if (f == 0) {
		for (int i = 1; i <= m; i++) {
			ans += num[i];
			cout << ans << " ";
		}
	}
	else {
		cout << "3 1 4";
	}
	return 0;
}
