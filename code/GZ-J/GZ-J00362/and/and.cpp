//GZ-J00362 华东附校 蒋一辰 
#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200005], b[200005];
int ma;

string ejz(int num){
	string jg = "";
	while(num){
		jg += num%2 + '0';
		num /= 2;
	}
	return jg;
}

int awy(int x, int y){
	string s1 = ejz(x), s2 = ejz(y);
	int sumn = 0, v = 1;
		for(int i = 0; i < min(s1.size(), s2.size()); i++){
			if(s1[i] == '1' && s2[i] == '1'){
				sumn += v;
			}
			v *= 2;
		}
	
	
	return sumn;
}

void dfs(int k, int x){
	if(k == m+1){
		int ans = INT_MAX;
		for(int i = 1; i <= m; i++) ans = awy(a[b[i]], ans);
		ma = max(ma, ans);
	}else{
		for(int i = x+1; i <= n; i++){
			b[k] = i;
			dfs(k+1, i);
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ma;
	return 0;
}

