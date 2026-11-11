#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500005;
int n;
ll m;
ll a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum > m) {
			printf("%d", i - 1);
			return 0;
		}
	}
	printf("%d", n);
	return 0;
}
