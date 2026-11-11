#include <bits/stdc++.h>
using namespace std;
const int p = 2e5 + 1;
int n, m, a[p], d[p];
int ans[p], flag[p];
map <int, int> mp; // 记录第i张牌的第一次出现位置 
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		mp.clear(); int l = 0;
		for (int j = i; j <= n; j++) {
			if (mp[a[j]] != 0) {
				for (int k = mp[a[j]] + 1; k <= l; k++)
					mp[d[k]] = 0;
				l = mp[a[j]];
			} else mp[a[j]] = j, d[++l] = a[j];
		}
		memset(flag, 0, sizeof flag);
		for (int j = 1; j <= l; j++) {
			if (flag[d[j]]) continue;
			ans[d[j]]++, flag[d[j]] = true;	
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
}
