#include<bits/stdc++.h>
#define pf first
#define ps second
using namespace std;
const int MAX = 2e6 + 5;
int c, t, n, d;
int x[MAX];
int f1[MAX], f2[MAX];
vector<pair<int, int>> lr;
pair<int, int> dfs(int st, int ed, int op, int step){
	if(step > op) return {0, op};
	if(st == ed){
		if(step <= op){
			return {1, step};
		}else return {0, op};
	}
	int ans = 0;
	for(int i = st + 1; x[i] - x[st] <= d && i <= ed; i++){
		auto [a, b] = dfs(i, ed, op, step + 1);
		if(b < op) op = b, ans = 1;
		else ans += a;
	}
	return {ans, op};
}
inline void solve(){
	int ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
		f1[i] = 1e9;
	}
	for(int st = 1; st < n; st++){
		for(int ed = st + 1; ed <= n; ed++){
			if(dfs(st, ed, 1e9, 0).first == 2) ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
