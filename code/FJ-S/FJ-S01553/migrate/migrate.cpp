#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,T;
const int N = 2 * 1e6 + 5;
ll gcd(ll a,ll b) {
	if (a % b == 0) return b;
	return gcd(b,a % b);
}

void slove() {
	ll a[N],dd[N];
	int xx[N];
	int n;
	ll d,dis;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dd[i] = a[i] + d;
		if (i > 2) dis = a[i] - a[i- 1];
	}
	if (dis > d) {
		cout << 0 << '\n';
	} else if (dis == d) {
		cout << 0 << '\n';
	} else {
		ll lcm = d / gcd(d,dis) * dis * 2;
	    cout << n - lcm + 1 << '\n';
	}
	
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--) {
		slove();
	}
	return 0;
}
