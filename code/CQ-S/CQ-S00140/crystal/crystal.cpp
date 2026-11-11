#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
const int N = 1e6 + 5;
int n, m, a[N], s[N]; 
bool check(int x, int y) {
	int res = s[y] - s[x - 1];
	return (a[y] * (y - x + 1) - res) <= m;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int ANS = 0;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i, ans = i;
		while(l <= r) {
			int mid = (l + r + 1) >> 1;
			if(check(mid, i)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		ANS = max(ANS, i - ans + 1);
	}
	cout << ANS;
	return 0;
}

