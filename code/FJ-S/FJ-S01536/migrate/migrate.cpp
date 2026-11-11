#include <bits/stdc++.h>
using namespace std;

typedef long long intL;
const int maxn = 2e6+6;

intL n, d, a[maxn], s[maxn];

void solve();

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--)
		solve();
	return 0;
}

void solve(){
	scanf("%lld%lld", &n, &d);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		s[i] = a[i] - a[1];
	}
	intL ans = 0;
	for(int i = 1;i <= n - 3;i++){
		if(a[i + 3] - a[i] > d && a[i + 3] - a[i] <= 2 * d)
			ans++;
	}
	printf("%lld\n", ans);
	return;
}
