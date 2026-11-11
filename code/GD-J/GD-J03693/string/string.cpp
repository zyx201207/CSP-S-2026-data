#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[200005];
char c[200005];
string s;
string t;
ll cnt;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		for (ll j = 1; j <= a[i]; j ++) {
			s += c[i];
		}
	}
	ll mid = s.size() / 2;
	ll l = mid - 1, r = mid + 1;
	ll minl = 0, maxr = s.size() - 1;
	while (l >= minl && r <= maxr) {
		if (l == minl && r == maxr) {
			if (s[l] == s[r]) {
				break;
			}
			else if (s[l + 1] == s[r - 1]) {
				s[l] = s[l + 1], s[r] = s[l + 1];
				cnt ++;
				break;
			} else {
				s[l] = s[mid], s[r] = s[mid], cnt += 2;
				break;
			}
		}
		if (s[l] == s[r]) {
			l --, r ++;
			continue;
		} else {
			if (s[l - 1] == s[r + 1]) {
				if (s[l] == s[l - 1]) {
					s[r] = s[l - 1], cnt ++;
				}
				else if (s[r] == s[l - 1]) s[l] = s[l - 1], cnt ++;
			} else {
				cnt ++;
				s[l] = s[mid], s[r] = s[mid];
			}
		}
		l --, r ++;
	}
	cout << cnt;
	return 0;
}
