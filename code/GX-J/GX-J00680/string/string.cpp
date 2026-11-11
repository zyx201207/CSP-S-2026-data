#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N =6e7+10;
string s[N];
int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ll n;
	cin >> n;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		ll a;
		char c;
		cin >> a >> c;
		for (int j = idx; j < idx + a; j++) {
			s[j] = c;
		}
		idx += a;
	}
	ll cnt = 0;
	for (int i = 0; i < floor(0.5 * idx); i++) {
		for (int j = idx - 1; j > floor(0.5 * idx); j--) {
			if (j <= idx && s[i] != s[j]) {
				cnt++;
			}
			i++;
		}
	}
	cout << cnt << endl;
	return 0;
}
