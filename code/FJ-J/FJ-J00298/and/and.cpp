#include<bits/stdc++.h>
using namespace std;

int n, m;//n:整数数量 m:选取的整数数量
int a[200005] = {};//a[i] -> 第i个整数
int ans = 0;//ans:答案 
bool vis[200005] = {};
string s[200005] = {};//s[i] -> 第i个数的二进制 

string an(string x, string y){
	string re = "";
	for(int i = 0; i <= min(x.length(), y.length()) - 1; i++){
		if(x[i] == y[i] && x[i] == '1')re = re + "1";
		else re = re + "0";
	}
	return re;
}

int solve(string x){
	int p = 1;
	int re = 0;
	for(int i = x.length() - 1; i >= 0; i--){
		if(x[i] == '1'){
			re += p;
		}
		p *= 2;
	}
	return re;
}

void dfs(int cnt, string sum){
	if(cnt == m){
		ans = max(solve(sum), ans);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		vis[i] = true;
		dfs(cnt + 1, an(sum, s[i]));
		vis[i] = false;
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		while(a[i] != 0){
			if(a[i] & 1 == 1)s[i] = "1" + s[i];
			a[i] /= 2;
		}
	}
	for(int i = 1; i <= n; i++){
		vis[i] = true;
		dfs(1, s[i]);
		vis[i] = false;
	}
	
	cout << ans;
	
	return 0;
} 
