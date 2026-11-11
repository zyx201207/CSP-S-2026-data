// 100pts
// erased special A & B because worried about it's wrong
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int MAXN = 500005;
LL a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	LL m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	LL ans = 1;
	LL l = 1, r = 0;
	LL tot = 0;
	while (r <= n) {
		LL delta = a[r] - a[r - 1];
		LL need = r - l;
		LL cost = delta * need;
		if (tot + cost > m) {
			ans = max(ans, r - l);
			while (tot + cost > m) {
				cost -= a[r] - a[l];
				l++;
			}
		} tot += cost;
		r++;
	} cout << ans << endl;
	return 0;
}
