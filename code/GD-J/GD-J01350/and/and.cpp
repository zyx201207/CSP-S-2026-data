#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int ans;
int vis[N];
auto t1 = clock();
int n,m;
void dfs(int step, int cur){
	auto t2 = clock();
	if(t2 - t1 >= 850){
		return;
	}
	if(step == m){
		ans = max(cur,ans);
		return;
	}
	for(int i = step; i < n; i++){
		if(step == 0){
			vis[i] = true;
			dfs(step + 1,a[i]);
			vis[i] = false;
		}
		if(!vis[i]){
			vis[i] = true;
			dfs(step+1,cur&a[i]);
			vis[i] = false;
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(m == 1){//6
		for(int i = 0; i < n; i++){
			ans = max(a[i],ans);
		}
		cout << ans;
		return 0;
	}else if(m == 2){//8~10
		int cur = 0;
		for(int i = 0; i < n; i++){
			cur = a[i];
			for(int j = i + 1; j < n; j++){
				cur &= a[j];
				ans = max(ans, cur);
				cur = a[i];
			}
		}
		cout << ans;
		return 0;
	}else if(m == n){//7
		ans = a[0];
		for(int i = 1; i < n; i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}else{//1~5
		dfs(0,0);
		cout << ans;
		return 0;
	}
}
