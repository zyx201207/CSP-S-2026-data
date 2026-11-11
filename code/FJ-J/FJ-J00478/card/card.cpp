#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int ans[300005];
int n, m;
bool speA() {
	for(int i = 1; i < n; i ++) {
		if(a[i] > a[i + 1]) {
			return false;
		} 
	} 
	return true;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if(speA()) {
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				ans[a[j]] ++;
			}
		}
		for(int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
		return 0;
	}
	if(m == 1) {
		cout << n;
		return 0;
	}
	if(m == 2) {
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 1 || a[n] == 1) {
				ans[1] ++;
			}
			if(a[i] == 2 || a[n] == 2) {
				ans[2] ++;
			}
		}
		cout << ans[1] << ' ' << ans[2];
	}
	return 0;
}

