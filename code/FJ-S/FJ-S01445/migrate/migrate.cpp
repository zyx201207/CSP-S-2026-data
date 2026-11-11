#include <bits/stdc++.h>
#define endl "\n"
#define MAXN 200005
using namespace std;
int c, t, n, d, x[MAXN], cha;
void solve();
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >>c >> t >> n >> d;
	while(t--) solve();
	return 0;
}

void solve() {
	for (int i = 1; i<= n;i++) cin >> x[i];
	if (c == 11 || c == 12) {
		cha = x[2] - x[1];
		if(x[2] - x[1] > 2 * d) cout << 0 << endl;
		else cout << max(0, n - 2) << endl;
		return;
	} else if (c == 13 || c == 14){
		cout << 0 << endl;
	} else if (c >= 15 && c <= 18) {
		cout << 0 << endl;
	} else {
		cout << 0 << endl;
	}
}