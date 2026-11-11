#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, s[N];
struct node {
	int x;
	char c;
} a[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int maxn = 0;
	for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].c, maxn = max(maxn, a[i].x);
	if(n * maxn <= 200000000) {
		string s = "";
		for(int i = 1; i <= n; i++) {
			int x = a[i].x; char c = a[i].c;
			for(int j = 1; j <= x; j++) s += c;
		} 
		n = s.size();
		s = " " + s;
		if(n % 2) {
			int l = n / 2, r = n / 2 + 2;
			int cnt = 0;
			while(1 <= l && r <= n) {
				if(s[l] != s[r]) cnt++;
				l--, r++;
			}
			cout << cnt;
		} else {
			int l = n / 2, r = n / 2 + 1;
			int cnt = 0;
			while(1 <= l && r <= n) {
				if(s[l] != s[r]) cnt++;
				l--, r++;
			}
			cout << cnt;
		}
		return 0;
	}
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i].x;
	int l;
	if(s[n] % 2) l = lower_bound(s + 1, s + n + 1, s[n] / 2 + 1) - s + 1;
	else l = lower_bound(s + 1, s + n + 1, s[n] / 2) - s;
	int r = n - l + 1, ans = 0;
	if(l == r) {
		if(s[n] / 2 - s[l - 1] != a[l].x - (s[n] / 2 - s[l - 1])) {
			int ll = a[l].x - s[n] / 2 + s[l + 1], rr = a[l].x - ll;
			if(ll > rr) a[l - 1].x += ll - rr;
			else a[r + 1].x += rr - ll;
		}
		l--, r++;
	}
	while(1 <= l && r <= n) {
		if(a[l].c != a[r].c) ans += min(a[l].x, a[r].x);
		if(a[l].x > a[r].x) a[l - 1].x += a[l].x - a[r].x;
		else a[r + 1].x += a[r].x - a[l].x;
		l--, r++;
	}
	cout << ans;
	return 0;
}
