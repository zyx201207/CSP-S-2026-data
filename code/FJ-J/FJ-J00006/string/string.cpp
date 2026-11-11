#include<bits/stdc++.h>
#define pii pair<ll, char>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
ll n, a[N], ans, now, suma, summ;
char c[N];
stack<pii> stk;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	for (int i = 1; i <= n; i++) suma += a[i];
	summ = suma / 2;
	for (int i = 1; i <= n; i++) {
		now += a[i];
		if (now <= summ) {
			stk.push(make_pair(a[i], c[i]));
			continue;
		}
		if (now - a[i] <= summ) {
			stk.push(make_pair(a[i] - now + summ, c[i]));
			a[i] = now - ((suma & 1) ? summ + 1 : summ);			
		}
		while (!stk.empty()) {
			pii pir = stk.top(); stk.pop();
			int k = min(a[i], pir.first);
			a[i] -= k; pir.first -= k;
			if (c[i] != pir.second) ans += k;
			if (pir.first > 0) stk.push(pir);
			if (a[i] <= 0) break;
		}
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
}
