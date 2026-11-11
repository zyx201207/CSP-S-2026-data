#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll crystal[500050];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> crystal[i];
	}
	sort(crystal, crystal + n);
	ll total = 0;
	ll ans = 0;
	ll maxans = -1;
	for (int i = n - 1; i >= (int)(n / 2) - 1; --i) {
		total = 0;
		ans = 1;
		for (int j = i - 1; j >= 0; --j) {
			ll chazhi = crystal[i] - crystal[j];
//			cout << i << " : " << j << " : " << chazhi << " | 	";
			if (total + chazhi <= m) {
				total += chazhi;
				ans++;
			} else {
				break;
			}
		}
		cout << "i :" << i << "| ans :" << ans << endl;
		maxans = max(maxans, ans);
//		cout << "ans:" << ans << " maxans:" << maxans << endl;
	}
//	cout << endl;
	cout << maxans << endl;
	return 0;
}
