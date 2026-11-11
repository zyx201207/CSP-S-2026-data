#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int M = 300005;
int n, m;
int a[N], cnt[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) 
		printf("%lld ", i);
	return 0;
}
