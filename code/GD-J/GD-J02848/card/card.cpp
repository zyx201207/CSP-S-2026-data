#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
long long n, m, a[500005], ans[300005], desk[500005], r, dianshu[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i ++) {
		r = 1;
		for(int j = 1; j <= m; j ++) {
			dianshu[j] = INF;
		}	
		for(int p = i; p <= n; p ++) {
			if(dianshu[a[p]] == INF) {
				desk[r] = a[p];
				dianshu[a[p]] = r;
				r ++;
			} else {
				for(int k = dianshu[a[p]] + 1; k <= r; k ++) {
					if(dianshu[desk[k]] == k) {
						dianshu[desk[k]] = INF;
					}
				}
				r = dianshu[a[p]] + 1;
			}
		}
		for(int j = 1; j < r; j ++) {
			ans[desk[j]] ++;
		}
	}
	for(int i = 1; i <= m; i ++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}
