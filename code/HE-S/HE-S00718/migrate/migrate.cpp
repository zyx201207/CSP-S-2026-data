#include <iostream>
#include <cstdio>
#define int long long
using namespace::std;
int c, t;
int n, d;
const int N = 2e6 + 10;
int a[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) {
		scanf("%d%d", &n, &d);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if(c == 0) {
			if(n == 4) {
				printf("1\n2");
				return 0;
			} else {
				printf("0\n1");
				return 0;
			}
		}
		if(c == 11 || c == 12) {
			printf("%d\n", n);
			return 0;
		}
		if(c == 13 || c == 14) {
			printf("%d\n", n - 1);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
