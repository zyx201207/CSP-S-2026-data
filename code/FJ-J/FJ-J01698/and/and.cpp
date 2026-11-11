#include<bits/stdc++.h>
using namespace std;
int n, m;
long long  ans, sum, e[200010];
bool vis[200010];
void dfs(int k, long long u){
	if(k > m){
		ans = max(ans, u);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(k == 1){
			vis[i]=1;
			dfs(k+1,e[i]);
			vis[i] = 0;
		}else if(!vis[i]){
			vis[i] = 1;
			dfs(k+1, (u & e[i]));
			vis[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> e[i];
	}
	sum = e[1];
	for(int i = 2; i <= n; i++){
		sum = (sum & e[i]);
	}
	if(m==n){
		cout << sum;
	}else{
		dfs(1, 0);
		cout << ans;
	}
	return 0;
}