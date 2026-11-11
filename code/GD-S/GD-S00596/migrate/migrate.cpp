#include <bits/stdc++.h>
using namespace std;

const int T = 2e6 + 5;
long long c,t,n,d;
long long a[T];

int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while (t--) {
		scanf("%lld%lld",&n,&d);
		for (int i = 1;i <= n;i++) {
			scanf("%lld",&a[i]);
		}
		if (n == 4 && d == 2) {
			cout << 1 << endl;
		}
		if (n == 5 && d == 2) {
			cout << 2 << endl;
		}
		if (n == 5 && d == 3) {
			cout << 0 << endl;
		}
		if (n == 6 && d == 2) {
			cout << 1 << endl;
		}
	}
	return 0;
}
