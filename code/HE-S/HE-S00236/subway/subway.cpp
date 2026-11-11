#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll maxn = 505;
ll w[maxn];
ll c, n, m, d, q;
ll k[maxn];
ll a[maxn], t[maxn];
ll sum;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		cin >> a[i] >> t[i];
	}
	for (int i = 1; i <= q; i++) {
		ll u, v;
		cin >> u >> v;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
