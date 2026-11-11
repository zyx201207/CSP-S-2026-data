#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], pos, ans[N], g[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	if(n * m <= 1e9) {
		for(int i = 1;i <= n; i ++) {
			cin >> a[i];
			g[a[i]] = i;
		}
		for(int i = 1;i <= n;i ++) {
	   		for(long long j = i; j <= n;j ++) {
	        	j = g[a[j]];
	        	ans[a[j]] ++;
			}
		}
		for(int i = 1;i <= m;i ++) cout << ans[i] << " ";
		return 0; 
	}
	bool flag = 1;
	for(int i = 1;i <= n; i ++) {
		cin >> a[i];
		g[a[i]] = i;
		if(a[i - 1] > a[i]) flag = 0;
	}
	if(flag) {
		for(int i = 1;i <= m;i ++) cout << g[i] << " ";
	}
	else {
		for(int i = 1;i <= n; i ++) {
			cin >> a[i];
			g[a[i]] = i;
		}
		for(int i = 1;i <= n;i ++) {
	   		for(long long j = i; j <= n;j ++) {
	        	j = g[a[j]];
	        	ans[a[j]] ++;
			}
		}
		for(int i = 1;i <= m;i ++) cout << ans[i] << " ";
	}
	return 0;
}
