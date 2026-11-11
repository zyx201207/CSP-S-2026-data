#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N];
int pre[N][35]; 
int ans = 0;
void dfs(int depth, int cnt) {
	if(cnt == m + 1){
		int p = 1, cur = 0;
		for(int i = 0;i <= 32;i++) {
			if(pre[m][i] == m) cur += p;
			p *= 2; 
		}
		ans = max(ans, cur);
		return;
	}
	if(depth == n + 1) return;
	int x = a[depth], sum = 0;
	while(x != 0) {
		pre[cnt][sum] = pre[cnt-1][sum] + x % 2;
		x >>= 1;
		sum++;
	}
	dfs(depth + 1,cnt + 1);
	for(int i = 1;i <= 32;i++) pre[cnt][i] = 0;
	dfs(depth + 1,cnt);
	return;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool flag = true;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		int x = a[i];
		while(x != 0) {
			if(x & 1 && x!=1) flag = true;
			x /= 2;
		}
	}
	if(m == 1) {
		sort(a + 1, a + 1 + n);
		cout << a[n];
		return 0;
	}
	if(m == 2) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1) {
		sort(a+1,a+1+n);
		ans = a[n];
		for(int i = n - 1;i >= 2;i--) ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	if(flag) {
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--) ans&=a[i];
		cout << ans;
		return 0;
	}
	dfs(1, 1);
	cout << ans;
	return 0;
}
