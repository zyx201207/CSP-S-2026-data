#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[500007];
bool vis[300007];
stack<long long> wsw;
long long cnt[300007];

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		a[i] -= 1;
	}
	
		for (int j = 0; j < n; j ++) {
			memset(vis, 0, sizeof(vis));
			for (int k = j; k < n; k ++) {
				if (vis[a[k]]) {
					while ((!wsw.empty()) && wsw.top() != a[k]) {
						wsw.pop();
					}
					vis[a[k]] = 0;
				} else {
					wsw.push(a[k]);
					vis[a[k]] = 1;
				}
			}
			
			while (!wsw.empty()) {
				for (int i = 0; i < m; i ++) {
					if (wsw.top() == i) {
						cnt[i] ++;
					}
				}
				wsw.pop();
			}
		}
	
	for (int i = 0; i < m; i ++) {
		cout << cnt[i] << " ";
	}
	
	return 0;
}
