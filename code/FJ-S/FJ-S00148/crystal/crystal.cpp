#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m, a[500010], c[500010];

int main() {
	freopen("crystal.in", "r", stdin);
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1 ; i <= n ; i++) c[i] = c[i - 1] + a[i];
	int L = 0, R = n + 1;
	while (L < R - 1) {
		int mid = (L + R) / 2;
		bool ok = false;
		for (int i = 1 ; i <= n - mid + 1 && !ok ; i++) {
			int j = i + mid - 1;
			ll k = a[j] * mid - c[j] + c[i - 1];
			if (k <= m) ok = true;
		}
		if (ok) L = mid;
		else R = mid;
	}
	printf("%d\n", L);
	return 0;
} 
