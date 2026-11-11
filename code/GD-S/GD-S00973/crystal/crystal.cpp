#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N];
int A = 1, B = 1, bn;
// 80
signed main() { // Oct31==Dec25?
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
		if (a[i] != i) A = 0;
		if (i == 2) bn = a[i] - a[i - 1];
		else if (a[i] - a[i - 1] != bn) B = 0;
	}
	sort(a + 1, a + 1 + n);
	
	if (A || B) {
		int cnt = 1, m_ = m;
		for (int i = n; i >= 1; i--) {
			if (m_ >= a[n] - a[i]) {
				cnt++;
				m_ -= a[n] - a[i];
			} else {
				break;
			}
		}
		cout << cnt;
		return 0;
	} else if (m >= 1e10) {
		cout << n;
		return 0;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 1, m_ = m;
		for (int j = i - 1; j >= 1; j--) {
			if (m_ >= a[i] - a[j]) {
				cnt++;
				m_ -= a[i] - a[j];
			} else {
				break;
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 17
1 2 4 8 9

-> 4


3 1
-10 1 2

-> 2
*/
