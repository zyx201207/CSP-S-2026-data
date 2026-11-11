#include <bits/stdc++.h>
using namespace std;


int n, m;
long long ans;
long long a[200010];
int main() {
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 30; j >= 0; j--) {
		int c, p;
		c = 0, p = 0;
		for (int i = 1; i <= n; i++) {
			if ((a[i] >> j) & 1) {
				swap(a[i], a[++p]);
				c++;
			}
		}
		if (c >= m) {
			n = p;
			ans |= (1LL << j);
		}
	}
	cout << ans << endl;
	return 0;
}
