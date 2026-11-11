#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 5e5 + 10;
int a[maxn], lst[maxn];
int cnt[maxn];
bool vis[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) lst[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j = lst[a[j]] + 1) {
			if (!vis[a[j]]) cnt[a[j]]++;
			vis[a[j]] = true;
		}
		for (int j = i; j <= n; j = lst[a[j]] + 1) vis[a[j]] = false;
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << (i < m ? " " : "\n");
	return 0;
}

