#include <iostream>
using namespace std;

int n, m, a[229028], digit[50], ans;
bool vis[229028];

inline void increase(int x) {
	int i = 0;
	while (x) digit[i++] += x & 1, x >>= 1;
}

inline void reduce(int x) {
	int i = 0;
	while (x) digit[i++] -= x & 1, x >>= 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], increase(a[i]);
	
	for (int i = 30; i >= 0; i--) {
		if (digit[i] >= m) {
			ans += 1 << i;
			for (int j = 1; j <= n; j++) {
				if (a[j] >> i & 1 || vis[j]) continue;
				reduce(a[j]);
				vis[j] = 1;
			}
		}
	}
	
	cout << ans;
	return 0;
}

