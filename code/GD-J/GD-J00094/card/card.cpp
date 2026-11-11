#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int a[N];
int cnt[M];
int lst[M];
int q[N];
int tot = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n > 5000 && m > 3000) {
		for(int i = 1; i <= n; i++) {
			lst[a[i]] = i;
		}
		n = unique(a + 1, a + 1 + n) - a - 1;
		for(int i = 1; i <= n; i++) {
			cnt[a[i]] += lst[a[i]];
		}
		for(int i = 1; i <= m; i++) cout << cnt[i] << ' ';
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		memset(lst, 0, 4 * (m + 1));
		tot = 0;
		for(int j = i; j <= n; j++) {
			if(lst[a[j]]) {
				for(int k = lst[a[j]] + 1; k <= tot; k++) lst[q[k]] = 0, q[k] = 0;
				tot = lst[a[j]] - 1;
			}
			q[++tot] = a[j];
			lst[a[j]] = tot;
		}
		for(int k = 1; k <= tot; k++) {
			cnt[q[k]]++;	
		}
	}

	for(int i = 1; i <= m; i++) cout << cnt[i] << ' ';
	
	return 0;
}
