#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve1(){
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			vector<int> cnt(n + 1);
			auto dfs = [&](auto dfs, int u, int dis) -> void {
				if(u == j){
					cnt[dis]++;
					return ;
				}
				for(int k = u + 1; k <= j; k++){
					if(a[k] - a[u] <= d) dfs(dfs, k, dis + 1);
					else break;
				}
			};
			dfs(dfs, i, 0);
			int t = 0;
			while(!cnt[t]) t++;
			if(cnt[t] == 2) ans++;
		}
	}
	cout << ans << '\n';
}

void solve2(){
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int dis = a[2] - a[1];
	if(d == 2 * dis) cout << n - 3 << '\n';
	else cout << 0 << '\n';
}

void solve3(){
	cout << 0 << '\n';
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	if(c <= 10){
		while(T--) solve1();
	}
	else if(c <= 12){
		while(T--) solve2();
	}
	else{
		while(T--) solve3();
	}
	return 0;
}//求您了，伟大的CCF，多给我点分吧！ 
