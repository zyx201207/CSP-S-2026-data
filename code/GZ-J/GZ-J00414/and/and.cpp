// GZ_J00414 张苇然 实验三中 
#include <bits/stdc++.h>
#define ll long long
#define vll vector <ll>
#define pll pair <ll,ll>
using namespace std;


int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vll a (n + 1,0);
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (m <= 2) {
		if (m == 1) {
			sort(a.begin() + 1,a.end());
			cout << a[n];
		}
		else if (m == 2) {
			ll ma = -LLONG_MAX;
			for (int i = 1;i <= n;i++) {
				for (int j = i + 1;j <= n;j++) {
					ma = max(a[i] & a[j],ma);
				}
			}
			cout << ma;
		}
	}
	else if (m == n) {
		ll ans = a[1];
		for (int i = 2;i <= n;i++) {
			ans &= a[i];
		}
		cout << ans;
	}
	else if (m == n - 1) {
		sort(a.begin() + 1,a.end());
		ll ans = a[2];
		for (int i = 3;i <= n;i++) ans &= a[i];
		cout << ans;
	}
	else if (n <= 20) {
		vll b;
		ll ma = -LLONG_MAX;
		for (int i = 1;i <= n;i++) {
			b.push_back(i);
		}
		do {
			ll ans = a[b[0]];
			for (int i = 1;i < m;i++) ans &= a[b[i]];
			ma = max(ma,ans);
		} while (next_permutation(b.begin(),b.end()));
		cout << ma;
	}
	else {
		sort(a.begin() + 1,a.end());
		cout << a[n - m + 1];
	}
	return 0;
}
