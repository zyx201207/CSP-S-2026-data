#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int n, m, a[200001];
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (m == 1) {
		sort(a + 1, a + n + 1, cmp);
		cout << a[1];
		return 0;
	}
	if (m == 2) {
		int maxn = -1;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (a[i] & a[j] > maxn) maxn = a[i] & a[j];
			}
		}
		cout << maxn;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	int minn = a[1];
	for (int i = 1;i <= m;i++) 
		if (a[i] < minn) 
			minn = a[i];
	cout << minn;
	return 0;
}
