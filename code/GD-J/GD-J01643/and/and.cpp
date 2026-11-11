#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;

const int M = 2e5 + 10;
long long a[M];
long long ans = -1;

int n, m;
bool vis[M];

bool cmp(int x, int y){
	return x > y;
}

void dfs(int use, int step, long long cur){
	if(step == m){
		ans = max(ans, cur);
		return;
	}
	for(int i = 1; i <= use; i++){
		if(!vis[i]){
			vis[i] = true;
			if(cur == -1){
				dfs(use, step + 1, a[i]);
			}
			else{
				dfs(use, step + 1, cur & a[i]);
			}
			vis[i] = false;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	// 一些特判
	if(m == 1){
		// 直接打擂
		for(int i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		} 
	} 
	else if(m == n){
		// 直接计算
		ans = a[1];
		for(int i = 2; i <= n; i++){
			ans &= a[i];
		} 
	}
	else if(m == 2){
		// 只考虑前32大
		sort(a + 1, a + 1 + n, cmp);
		dfs(min(32, n), 0, -1); 
	}
	else{
		// 听天由命吧
		dfs(n, 0, -1); 
	}
	
	cout << ans;
	return 0;
}
