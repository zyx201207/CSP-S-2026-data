#include <iostream>

using namespace std;

const int N = 2e5 + 10;
int n, a[N], K, ans;
bool can[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> K;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) can[i] = true;
	
	for (int k = 30; k >= 0; k --) {
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (!can[i]) continue;
			if (((a[i] >> k) & 1) == 1)
				cnt ++;
		}
		if (cnt >= K) {
			ans += (1 << k);
			for (int i = 1; i <= n; i ++) {
				if (!can[i]) continue;
				if (((a[i] >> k) & 1) == 0)
					can[i] = false;
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
