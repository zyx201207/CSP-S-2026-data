#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1;

int n, m, vis[N], a[N], ans = -1;

void dfs(int x, int sum){
	if(x == m){
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			if(sum == 0 && x == 0){
				dfs(x + 1, a[i]);
			}else{
				dfs(x + 1, sum & a[i]);
			}
			vis[i] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
} 
