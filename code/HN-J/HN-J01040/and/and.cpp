#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;

int n, m, a[MAXN], mx, sum, ans;

namespace subtask1{
	int ans = -INF;
	void dfs(int x, int mxn){
		if(x == m){
			ans = max(ans, mxn);
		} 
		if(x < m){
			for(int i = 1; i <= n; i++){
				dfs(x + 1, mxn & a[i]);
			}
		}
	}
	void solve(){
		dfs(1, 0);
		cout << ans;
	}
}

namespace subtask2{
	void solve(){
		cout << mx;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	mx = -INF;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if(n <= 20){
		subtask1::solve();
	} 
	if(m == 1){
		subtask2::solve(); 
	}
	if(m == n){
		sum = a[1];
		for(int i = 2; i <= n; i++){
			sum &= a[i];
		}
		cout << sum;
	} 
	ans == -INF;
	if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j){
					continue;
				}
				ans = max(ans, a[i] & a[j]);
			} 
		}
		cout << ans;
	}
	return 0;
} 
