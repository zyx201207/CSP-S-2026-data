#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 5e5;
ll a[MAXN | 1];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ull m;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	
	sort(a + 1, a + n + 1);
	
	int ans = 0;
	int l = 1;
	ull payload = 0; 
	for (int i = 2; i <= n; ++i) {
		payload += (ull)(i - l) * (a[i] - a[i - 1]);
		while (payload > m) {
			payload -= a[i] - a[l++];
		}
		ans = max(ans, i - l + 1);
	}
	
	printf("%d", ans);
	return 0;
}
