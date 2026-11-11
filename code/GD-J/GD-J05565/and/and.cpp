#include <iostream>
using namespace std;
int n, m, ans;
int a[200005];
void dfs(int x, int y, int v){
	if(y == m){
		ans = max(v, ans);
		return;
	}
	if(x > n) return;
	dfs(x + 1, y, v);
	dfs(x + 1, y + 1, v & a[x]);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == m){
		int t = a[1];
		for(int i = 2; i <= n; i++) t = t & a[i];
		cout << t;
		return 0;
	}
	else if(m == 1){
		int maxn = 0;
		for(int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
		cout << maxn;
		return 0;
	}
	else if(m == 2){
		int maxn = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		dfs(1, 0, a[i]);
	}
	cout << ans;
	return 0;
}
