#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
long long ans = -1;
bool used[200005];
inline long long dfs1(int lv){
	long long res;
	if(lv == m+1){
		res = -1;
		for(int i = 1; i <= n; i++){
			if(used[i]){
				res &= a[i];
			}
		}
	}
	else{
		res = -1e9;
		for(int i = 1; i <= n; i++){
			if(used[i]){
				continue;
			}
			used[i] = true;
			res = max(res, dfs1(lv+1));
			used[i] = false;
		}
	}
	return res;
}
/*inline long long dfs2(int lv){
	long long res;
	if(lv == m){
		res = -1;
		for(int i = 1; i <= n; i++){
			if(!used[i]){
				res = res & a[i];
			}
		}
	}
	else{
		res = -1e9;
		for(int i = 1; i <= n; i++){
			if(used[i]){
				continue;
			}
			used[i] = true;
			res = max(res, dfs1(lv-1));
			used[i] = false;
		}
	}
	return res;
}*/
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, greater<int>());
	if(n != m){
		/*if(m < n/2){
			for(int i = 1; i <= n-m; i++)*/
				ans = dfs1(1);
		/*}
		else{
			for(int i = n; i >= m; i--)
				ans = dfs2(n);
		}*/
	}
	else if(n == m){
		for(int i = 1; i <= n; i++)
			ans &= a[i];
	}
	else if(m == n-1){
		for(int i = 1; i <= n; i++){
			long long ans_ = -1;
			for(int j = 1; j <= n; j++){
				if(j == i) continue;
				else{
					ans_ &= a[j];
				}
			}
			ans = max(ans, ans_);
		}
	}
	cout << ans;
	return 0;
} 
