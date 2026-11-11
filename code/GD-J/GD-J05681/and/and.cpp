#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int n, m;
int ans = 0;
void dfs(int x, int index, int cnt){
	if (x == m){
		ans = max(ans, cnt);
		return;
	}
	for (int i = index+1; i <= n; i++){
		if (x == 0){
			cnt = a[i];
		}
		dfs(x+1, i, cnt&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
} 
