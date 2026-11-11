#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll c, t;
ll n, d;
const ll maxn = 2 * 1e6 + 10;
ll a[maxn];
ll dis[maxn];
bool key = false;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ll cha;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i == 2) {
				cha = a[i] - a[i-1];
			}
		}
		if (cha >= d || cha * 2 > d) {
			cout << 0 << endl;
		}
		else {
			ll time = d / cha;
			ll s = (time * 2 - 1) * cha;
			ll all = cha * n;
			ll sheng = all - s;
			if (sheng / cha < 0) {
				cout << 0 << endl;
			}
			else cout << sheng / cha << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
