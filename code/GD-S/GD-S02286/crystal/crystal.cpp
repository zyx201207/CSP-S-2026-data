#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N], s[N];

int getcount(int l, int r) {
	return s[r] - s[l - 1];
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m, ans = 0, res;
	cin >> n >> m;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1, j = 2; j <= n; j++) {
		while(i < j && a[j] * (j - i) - getcount(i, j - 1) > m) {
			i++;
		}
		int res = a[j] * (j - i) - getcount(i, j - 1);
		if(res <= m)  {
			ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
