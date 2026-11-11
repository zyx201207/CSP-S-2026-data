#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n, m;
int a[maxn];
int d;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 1) {
		cout << 1;
		return 0;
	}
	d = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != d) f = 0;
	}
	if (f == 1) {
		int i = 1;
		for (; i <= n; i++) {
//			cout << (i - 1) * i / 2 << '\n';
			if ((i - 1) * i / 2 > m / d) {
				break;
			}
		}
		i--;
		cout << i;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int now = 0;
		int p = a[i];
		int cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			now += (p - a[j]);
			if(now > m) break;
			cnt++;
		}
		ans = max(ans, cnt);
	} 
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
