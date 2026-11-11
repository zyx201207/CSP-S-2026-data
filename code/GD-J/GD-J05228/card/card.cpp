#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;

int n, m, a[MAXN], pos[MAXM][2];

long long ans[MAXM];
bool vis[MAXM];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]][0] = min(pos[a[i]][0], i);
		pos[a[i]][1] = max(pos[a[i]][1], i);
	}
	
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		for (int j = pos[a[i]][1]; j <= n;) {
			if (!vis[a[j]]) {
				ans[a[j]]++;
				vis[a[j]] = 1;
			}
			if (pos[a[j]][1] == j) {
				j++;
			}
			else {
				j = pos[a[j]][1];
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
