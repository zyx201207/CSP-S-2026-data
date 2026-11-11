#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, m, a[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int po;
		for (int j = i; j < i; j++) {
			if (a[j] == a[j + 1]) {
				po = j + 1;
			}
		}
		for (int i = po; i <= n; i++) {
			ans[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
