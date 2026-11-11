#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e5 + 5, maxm = 3e5 + 5;
int n, m, a[maxn], cnt[maxm], cards[maxn];
bool flag = true;

signed main() {
	(void)freopen("card.in", "r", stdin);
	(void)freopen("card.out", "w", stdout);
	(void)scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		(void)scanf("%lld", &a[i]);
		if(a[i] < a[i - 1]) flag = false;
	}
	for(int t = 1; t <= n; t++) {
		int p = 1;
		memset(cards, 0, sizeof cards);
		for(int i = t; i <= n; i++) {
			if((p != 1) && flag) {
				p = lower_bound(cards + 1, cards + p, a[i]) - cards;
			} else {
				for(int j = 1; j < p; j++) {
					if(cards[j] == a[i]) {
						p = j;
						break;
					}
				}
			}
			cards[p] = a[i];
			p++;
		}
		for(int i = 1; i < p; i++) cnt[cards[i]]++;
	}
	for(int i = 1; i <= m; i++) (void)printf("%lld ", cnt[i]);
	return 0;
}
