#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n;
__int128 m;
__int128 a[N];
__int128 sum[N];

inline __int128 read() {
	__int128 x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
} 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read();
	m = read(); 
	for (int i = 1;i <= n;i++) a[i] = read();
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	
	int ans = 1;
	for (int i = 2;i <= n;i++) {
		int l = 0, r = i;
		int pos = 0;
		while (l <= r) {
			__int128 mid = (l + r) / 2;
			if (a[i] * (i - mid) * 1ll - (sum[i] - sum[mid]) <= m) {
				pos = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - pos);
	}
	cout << ans << '\n';
	return 0;
}
