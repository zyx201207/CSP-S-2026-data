#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a+1, a + n + 1);
	int ans = -10101010;
	if (m == 1) {
		ans = a[n];
	}else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				ans = max((a[i] & a[j]), ans);
			}
		}
	}else if (m == n - 1){
		bool f = false;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				f = true;
				ans = a[2];
			}
			else ans = a[1];
			for (int j = 2; j <= n; j++) {
				if (i == j) continue;
				if (f) {
					f = false;
					continue;
				}
				ans = ans & a[j]; 
			}
		}
	}else {
		cout << '0';
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
