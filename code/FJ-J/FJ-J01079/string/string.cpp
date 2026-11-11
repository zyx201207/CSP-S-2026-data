#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

int n;
ll a[MAXN];
char c[MAXN];
ll ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
	}
	
	int j = n;
	ll lst = 0;
	for (int i = 1; i <= n && i < j; i ++) {
		ll cnt = 0;
		while (cnt < a[i]) {
			if (lst) {
				cnt += lst;
			} else {
				cnt += a[j];
			}
			if (c[i] != c[j]) {
				if (lst) {
					ans += lst;
				} else {
					ans += a[j];
				}
			}
			lst = 0;
			if (cnt < a[i]) {
				j --;
			}
		}
		lst = cnt - a[i];
		if (c[i] != c[j]) {
			ans -= lst;
		}
		if (lst == 0) {
			j --;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
