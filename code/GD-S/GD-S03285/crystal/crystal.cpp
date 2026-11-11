#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5e4;
int n, m, ans, a[N], cha;
bool flag = true;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	cha = a[2] - a[1];
	for (int i = 3; i <= n; i++) if (a[i] - a[i - 1] != cha) flag = false;
	if (flag == true) {
		int _ = cha;
		while (m >= cha) {
			m -= cha;
			ans++;
			cha += _;
		}
		cout << ans + 1;
	}
	else {
		for (int i = 1; i <= n; i++) {
			int sum = 0, cnt = 1;
			for (int j = i - 1; j >= 1; j--) {
				int temp = a[i] - a[j]; 
				sum = sum + temp;
				if (sum > m) break ;
				cnt += 1;
			}
			if (ans < cnt) ans = cnt;
		}
		cout << ans;
	}
	return 0; 
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
