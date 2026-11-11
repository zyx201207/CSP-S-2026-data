#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N], pre[N], suf[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
	int l = 1, r = pre[n], posl = 1, posr = n;
	while (l <= r) { // ÏòÄÚÊÕËõ 
		if (pre[posl] + 1 - l <= r - pre[posr - 1]) {
			int x = pre[posl] + 1 - l;
			sum += x * (c[posl] != c[posr]);
			l += x, posl++;
			r -= x;
		} else {
			int x = r - pre[posr - 1];
			sum += x * (c[posl] != c[posr]);
			r -= x, posr--;
			l += x;
		}
	}
	cout << sum << '\n';
	return 0;
}
