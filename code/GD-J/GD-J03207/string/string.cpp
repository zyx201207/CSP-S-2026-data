//100 pts
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define pii pair<int,int>
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7; //998244353
int n;
int a[200005];
char c[200005];
ll cnt = 0;
ll s[200005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	ll l = 1, r, la = 1, ra = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
	}
	r = s[n];
	while (l <= r) {
		int lenl = s[la] - l + 1, lenr = r - s[ra - 1];
		if (lenl < lenr) {
			if (c[la] != c[ra]) cnt += lenl;
			l += lenl;
			++la;
			r -= lenl;
		} else if (lenl > lenr) {
			if (c[la] != c[ra]) cnt += lenr;
			l += lenr;
			r -= lenr;
			--ra;
		} else {
			if (c[la] != c[ra]) cnt += lenl;
			l += lenl;
			++la;
			r -= lenr;
			--ra;
		}
	}
	cout << cnt;
	return 0;
}
