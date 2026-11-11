//兰玉昊 GZ-J00057 观山湖中学
#include<bits/stdc++.h>
using namespace std;

int n, m, ans, a[200050];

void dfs(int k, int v, int s){
	if(k > m){
		ans = max(ans, v);
	}else{
		for(int i = s;i <= n - m + k;i++){
			dfs(k+1, v&a[i], i+1);
		}
	}
	return ;
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n - m + 1;i++){
		dfs(2, a[i], i+1);
	}
	cout << ans;
	return 0;
}
