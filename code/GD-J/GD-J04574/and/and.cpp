#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k;
int ans = 0, a[N];

void dfs(int now, int cnt, int lst){
	if(now == m){
		ans = max(ans, cnt);
		return;
	}
	for(int i = lst + 1; i <= n; i++){
		dfs(now + 1, cnt & a[i], i);
	}
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1) k = a[i];
		else k = k & a[i];
	}
	if(m == n){
		cout << k;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		dfs(1, a[i], i);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
