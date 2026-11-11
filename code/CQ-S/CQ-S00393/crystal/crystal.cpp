#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[5005];
int c[5005];
int maxx = 0;
void dfs(int x, int change, int jizhun) {
	for(int i = 1; i <= n; i++) {
		if(c[i]) continue;
		c[x] = 1;
		int t = abs(a[i]-a[jizhun]), p = a[i];
		if(change >= t) {
			if(a[jizhun] < a[i]) continue;
			a[i] = a[jizhun];
			dfs(i, change-t, jizhun);
			a[i] = p;
		} else {
			int cnt = 0;
			for(int j = 1; j <= n; j++) {
				if(a[j] == a[jizhun]) {
					cnt++;
				}
			}
			maxx = max(maxx, cnt);
			return ;
		}
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] == a[jizhun]) {
				cnt++;
			}
		}
		maxx = max(maxx, cnt);
	}
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if(n <= 2000) {
		for(int i = 1; i <= n; i++) {
			memset(c, 0, sizeof c);
			dfs(1, m, i);
		}
		cout << maxx;
	} else {
		int cnt = 0;
		for(int k = n; k >= 1; k--) {
			if(m >= abs(a[n]-a[k])) {
				m -= abs(a[n]-a[k]);
				cnt++;	
			}
		}
		cout << cnt;
	}
	
	return 0;
} 
