#include <bits/stdc++.h>

#define _for(i, a, b) for (int i= (a);i <= (int)(b); i++ )

using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
int n, ans;
LL m, a[N], s[N];

bool check(int r, int len){
	int l = r - len + 1;
	LL t = s[r]- s[l - 1];
	if (a[r] * len <= t + m) return 1;
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >>n >> m;
	_for (i, 1,n) cin >> a[i];
	sort(a + 1, a + n + 1);
	_for (i, 1, n) s[i] = s[i- 1] + a[i];
	_for (i, 1, n) {
		int l = 1, r = i;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (check(i, mid)) l = mid;
			else r = mid - 1;
		}
		ans = max(ans, l);
	}
	cout << ans;
	return 0;
}
