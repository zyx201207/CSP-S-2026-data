#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
long long m, a[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	long long sum = 0;
	int ans = 0, l = 1;
	for (int r = 1; r <= n; r++){
		sum += a[r];
		while (a[r] * (r - l + 1) - sum > m)
			sum -= a[l], ++l;
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
