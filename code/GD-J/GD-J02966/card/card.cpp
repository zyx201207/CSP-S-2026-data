#include <bits/stdc++.h>
using namespace std;

long long n, m, l;
long long arr[500010], vis[300010], cnt[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		for(int r = i; r <= n; r++) {
			if(vis[arr[r]] != 0) {
				for(int j = vis[arr[r]]; j < r; j++) {
					vis[arr[j]] = 0;
				}
			}
			vis[arr[r]] = r;
		}
		for(int j = 1; j <= m; j++) {
			if(vis[j] != 0) {
				cnt[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		printf("%lld ", cnt[i]);
	}
	cout << '\n';
	return 0;
}
