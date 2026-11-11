#include <bits/stdc++.h>
using namespace std;
const int N = 500011;

int n;
long long m, k, a [N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m), k = 0ll;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a [i]),
		k += a [i];
	sort(a + 1, a + n + 1);
	for (int i = n; i > 0; i--) {
		if (a [i] * i - k <= m) {
			printf("%d", i);
			return 0;
		}
		k -= a [i];
	}
	return 0;
}
