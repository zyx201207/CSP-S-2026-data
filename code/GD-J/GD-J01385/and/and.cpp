#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int ans = 0;
bool chs[200005];
void dfs(int last, int k){
	if (k >= m){
		ans = max(ans, last);
	}
	for (int i = 1; i <= n; i++){
		if (!chs[i]){
			chs[i] = 1;
			dfs(last & a[i], k + 1);
			chs[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (m == n){
		int s = 0x7fffffff;
		for (int i = 1; i <= n; i++){
			s = s & a[i];
		}
		cout << s;
		return 0;
	}
	if (m == 1){
		for (int i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	dfs(0x7fffffff, 0);
	cout << ans;
	return 0;
}
