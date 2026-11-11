#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200005;
ll arr[MAXN] = {}, n, m, anum = (ll)pow(2, 32), ans = 0;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (anum > 0) {
		ll oks = 0;
		bool can0 = false;
		//cout << anum << endl;
		for (int i = 0; i < n; i++) {
			if ((arr[i] & anum) != 0) {
				oks++;
				can0 = true;
			}
			//cout << arr[i] << ' ' << oks << endl;
		}
		if (oks >= m) {
			if (can0) {
				for (int i = 0; i < n; i++) {
					if ((arr[i] & anum) == 0) arr[i] = 0;
				}
				ans += anum;
			}
		}
		anum /= 2;
		//cout << "ans=" << ans << '\n';
	}
	cout << ans;
	return 0;
}
