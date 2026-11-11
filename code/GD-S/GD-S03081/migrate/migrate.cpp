#include<bits/stdc++.h>
using namespace std;

int n, d, x[50010], cnt[50010], dp[50010];

void dfs(int cur){
	if(cur > n) return;
	int maxx;
	for(maxx = cur; x[maxx+1] - x[maxx] <= d; maxx ++);
	for(int i = cur; i <= maxx; i ++){
		
	}
}

void solve1(){
	cin >> n >> d;
	for(int i = 1; i <= n; i ++){
		cin >> x[i];
	}
	dfs(1);
}

void solve2(){
	return;
}

void solve(){
	int dxsl = 1;
	cin >> n >> d;
	for(int i = 1; i <= n; i ++){
		cin >> x[i];
	}
	cout << n/2 << '\n'; 
}

int main(){
	int c, t;
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
