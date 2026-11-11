#include <bits/stdc++.h>
using namespace std;

int a[500010];
int ans[500010];
bool vis[500010];
int b[500010];
bool v[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = 1; j <= 500000; j++) {
			b[j] = 0;
			v[j] = false;
			vis[j] = false;
		}
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= cnt; k++) {
				if(vis[k]) continue;
				if(b[k] == a[j]) {
					for(int q = k; q <= cnt; q++) {
						vis[q] = true;
					}
					break;
				}
			}
			b[++cnt] = a[j];
		}
		for(int j = 1; j <= cnt; j++) {
			if(!vis[j] && !v[b[j]]) {
				ans[b[j]]++;
				v[b[j]] = true;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
