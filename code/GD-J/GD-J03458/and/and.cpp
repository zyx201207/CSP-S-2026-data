#include<bits/stdc++.h>
using namespace std;

int n, m, a[200010], ans = INT_MIN;

void dfs(int k, int pos, int cur){
	if(k >= m){
		ans = max(ans, cur);
		return;
	}
	if(pos > n) return;
	dfs(k+1, pos + 1, cur & a[pos]);
	dfs(k, pos + 1, cur);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int k = (1 << 30) - 1;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		k &= a[i];
	}
	if(m == 1){
		sort(a+1, a+1+n, greater<int>());
		cout << a[1];
	} else if(m == n) {
		cout << k;
	} else if(m == 2) {
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				if(i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	} else {
		dfs(0, 1, (1 << 30) - 1);
		cout << ans;
	}
	return 0;
}
