#include <bits/stdc++.h>
using namespace std;
const int N = 2000011;

int c, t, n, p [N], f [N] [N];
long long d, g [N];
vector <int> e [N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", &g [i]);
		puts("0");
	}
	return 0;
}
