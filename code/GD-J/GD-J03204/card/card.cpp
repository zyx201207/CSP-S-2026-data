#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, m, a[N], lst[N];
ll g[N], ans[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		g[i]++;
		ans[a[i]] += g[i];
		g[lst[a[i]] + 1] += g[i];
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
