#include<bits/stdc++.h>
using namespace std;
int c, t;
long long n, k, ui, vi, ans;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t --) {
		scanf("%lld%lld", &n, &k);
		for(int i = 1; i <= n - 1; i ++) {
			scanf("%lld%lld", &ui, &vi);
		}
		ans = (n - 1) / 2;
		ans = (ans + 1) / 2;
		ans -= (k / 2);
		ans = (ans / 2) + 1;
		printf("%lld", ans);
	}
	return 0;
}
