#include <bits/stdc++.h>
using namespace std;
const int max_n = 500001;
long long int a[max_n];
namespace my_namespace {
	int main() {
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		int n, ans = 1, l = 1;
		long long int m, d = 0;
		scanf("%d%lld", &n, &m);
		
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		
		sort(a + 1, a + n + 1);
		
		
		for (int i = 1; i < n; ++i) {
			
			while (m - d < (a[i + 1] - a[i]) * (i - l + 1)) {
				d -= a[i] - a[l++];
			}
			
			d += (a[i + 1] - a[i]) * (i - l + 1);
			ans = max(ans, i + 2 - l);
		}
		
		printf("%d\n", ans);
		return 0;
	}
}
int main() {
	return my_namespace::main();
}