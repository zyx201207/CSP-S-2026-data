#include <iostream>

using namespace std;

unsigned long long int n, d;
long long int a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	scanf("%d%d", &c, &t);
	
	for(int i = 0; i < t; i++) {
		scanf("%llud%llud", &n, &d);
		for(unsigned long long int j = 0; j < n; j++) scanf("%lld", &a[j]);
	}
	
	return 0;
}
