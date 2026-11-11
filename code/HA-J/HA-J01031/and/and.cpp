#include <bits/stdc++.h>
using namespace std;

int powOf2[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

int check(int x, int Bit) {
	int ans = powOf2[Bit];
	return (x & ans);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int max = 0;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) max = a[i];
	}
	max = floor(log2(max));
	bool elim[n];
	int ans = 0;
	for (int i = 0; i < n; i++) elim[i] = 1;
	for (int i = max; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (check(a[j], i) && elim[j]) cnt++;
		}
		if (cnt >= m) {
			ans += powOf2[i];
			for (int j = 0; j < n; j++) {
				if (!check(a[j], i)) elim[j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
