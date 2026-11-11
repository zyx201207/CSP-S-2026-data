#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10;
int n, m, a[N], cnt[N], s[N], b;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	freopen("card4.in", "r", stdin);
//	freopen("cards.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int l = 0;
		for (int j = i; j <= n; j++) {
			bool tt = false;
			for (int k = l; k >= 1; k--) {
				if (s[k] == a[j]) {
					l = k;
					tt = true;
					break;
				}
			}
			if (!tt) {
				s[++l] = a[j];
			}
		}
		for (int j = 1; j <= l; j++) {
			cnt[s[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld ", cnt[i]);
	}
	return 0;
}
