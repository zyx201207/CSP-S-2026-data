/*
09:56 开T3
09:57 无思路
09:57 希望能有个三等，感觉要AFO了，希望上迷惑行为大赏
10:30 已放弃
10:41 重开T3，暴力，预估60分
11:03 完成，预计50分
*/
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
bool vis[100];
int cnt;
int ans;

void dfs(int dep){
	if(dep > n){
		int res = -1;
		for(int i = 1;i <= n;i++){
			if(vis[i]){
				if(res == -1) res = a[i];
				else res &= a[i];
			}
		}
		if(cnt == m) ans = max(ans,res);
		return;
	}
	vis[dep] = 1;
	cnt++;
	dfs(dep + 1);
	vis[dep] = 0;
	cnt--;
	dfs(dep + 1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	// freopen("and1.in","r",stdin);
	// freopen("and1.out","w",stdout);

	// freopen("and2.in","r",stdin);
	// freopen("and2.out","w",stdout);

	// freopen("and3.in","r",stdin);
	// freopen("and3.out","w",stdout);

	// freopen("and4.in","r",stdin);
	// freopen("and4.out","w",stdout);

	// freopen("and5.in","r",stdin);
	// freopen("and5.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n <= 20){
		dfs(1);
		cout << ans;
		cout << '\n';
		return 0;
	}
	if(m == 1){
		for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
		cout << ans;
		cout << '\n';
		return 0;
	}
	if(m == n){
		for(int i = 1;i <= n;i++) ans &= a[i];
		cout << ans;
		cout << '\n';
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j) ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
		cout << '\n';
		return 0;
	}
	return 0;
}