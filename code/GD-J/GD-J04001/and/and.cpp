#include <stdio.h>
#include <string.h>
#include <vector>
long long a[200005];
std::vector<int> bits[40];
bool impossible[200005];
const int LG2 = 31;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= LG2; j++) {
			if (~a[i] >> j & 1) {
				bits[j].push_back(i);
			}
		}
	}
	long long res = 0;
	int sset = n;
	for (int i = LG2; i >= 0; i--) {
		int aft = sset;
		for (int j: bits[i]) {
			if (impossible[j] == 0) aft--;
		}
		if (aft >= m) {
			res |= 1LL << i;
			sset = aft;
			for (int j: bits[i]) {
				impossible[j] = 1;
			}
		}
	}
	printf("%lld", res);
	return 0;
} 
