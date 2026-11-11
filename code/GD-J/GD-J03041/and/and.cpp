#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	if(n <= 20) {
		int ans = a[1];
		for(int i = 2; i <= m; i++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	} else if(m == 1) {
		cout << a[1];
	} else {
		int ans = -1;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
	}
	return 0;
}
