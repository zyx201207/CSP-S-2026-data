#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200200], ans = 0;
char c[200200];
int s = 1;
signed main() {
	freopen("string.in" , "r", stdin );
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	int x = 1, y = n;
	while (y - x >= 1) {
		if (c[x] == c[y]) {
			if (a[x] > a[y]) {
				a[x] -= a[y];
				y--;
			}
			else {
				if (a[x] < a[y]) {
					a[y] -= a[x];
					x++;
				}
				else {
					x++;
					y--;
				}
			}
			continue; 
		}
		if (a[x] > a[y]) {
			a[x] -= a[y];
			ans += a[y];
			y--;
		}
		else {
			if (a[x] < a[y]) {
				a[y] -= a[x];
				ans += a[x];
				x++;
			}
			else {
				ans += a[x];
				x++;
				y--;
			}
		}
	}
	cout << ans;
	return 0;
}
