#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct st {
	ll num;
	char c;
}a[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %c", &a[i].num, &a[i].c);
	}
	if (n == 1) printf("0");
	else {
		if (a[1].c == a[2].c) printf("0");
		else printf("%lld", min(a[1].num, a[2].num));
	}
	return 0;
}
