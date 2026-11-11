#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500005;

int n, m;
ll s = 1, ans = 0;
ll a[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool sp_A = 1, sp_B = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != i) sp_A = 0;
	}
	memset(c, 0, sizeof(c)); 
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i) {
		c[i - 1] = a[i] - a[i - 1];
		if (c[i - 1] != 1) sp_B = 0;
	}
	if (sp_A) {
		int res = m;
		for (int i = 1; i <= n; ++i) {
			if (res >= i) res -= i;
			else {
				cout << i;
				return 0;
			}
		}
		cout << n;
	} else if (sp_B) {
		int res = m;
		for (int i = 1; i <= n; ++i) {
			if (res >= i) res -= i;
			else {
				cout << i;
				return 0;
			}
		}
		cout << n;
	} else {
		int now = 1;
		while (now <= n) {	
			if (c[now] == 0) s++;
			else if (m >= c[now] * s) {
				m -= c[now] * s, s++;
			} else {
				if (now != n - 1) 
					for (int i = now + 1; i <= n; ++i) {
						if (c[i] == 0) s++;
						else break;
					}
				ans += s;
				cout << ans;
				return 0;
			}	
			now++;
		}
	}
	return 0;
} 
