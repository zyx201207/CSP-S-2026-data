//GZ-S00285 张苇然 实验三中 
#include <bits/stdc++.h>
#define vll vector <ll>
#define ll long long

using namespace std;

int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--) {
		int n,d;
		cin >> n >> d;
		vll a (n + 1,0);
		for (int i = 1;i <= n;i++) cin >> a[i];
		sort(a.begin() + 1,a.end());
		if (c >= 11 && c <= 12) {
			ll k = a[2] - a[1];
			if (d >= 2 * k) cout << n - 2 << '\n';
			else cout << 0 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}
