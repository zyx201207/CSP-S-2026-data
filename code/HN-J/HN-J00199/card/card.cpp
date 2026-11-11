#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int ta[300005];
int vis[300005];
int ans[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	int cnt = 1;
	int k = n;
	while(k --) {
		memset(vis, -1, sizeof(vis));
		memset(ta, 0, sizeof(ta));
		int j = cnt;
		for(int i = cnt; i <= n;) {
			if(vis[a[i]] == -1) {
				vis[a[i]] = j;
			}	
			else {
				j = vis[a[i]];
				for(int x = j + 1; x < i; x ++) {
					if(vis[a[x]] < x) {} 
					else  vis[a[x]] = -1;
				}

			}
			ta[j] = a[i];
			i += 1;
			j += 1;
		}
		
		
		for(int i = cnt; i < j; i ++) {
			ans[ta[i]] += 1;
		}
		cnt += 1;
	}
	
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
