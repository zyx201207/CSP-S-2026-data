#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200001];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	printf("%lld\n", a[n]);
	return 0;
}





