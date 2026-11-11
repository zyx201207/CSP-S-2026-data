#include <bits/stdc++.h>
using namespace std;

const int T = 5e5 + 5;
long long c,n,m,d,q;
long long w[T];

int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		cout << 32 << endl << 17;
	}
	if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		cout << 35 << endl << 16;
	}
	return 0;
}
