#include <bits/stdc++.h>

#define LL long long

using namespace std;
const int N = 2e6 + 10;
LL x[N], ans;
LL g[N], f[N];
int dis[N], suf[N];
void solve(){
	int n;
	LL d;
	ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;i ++)
		cin >> x[i];
	for(int r = 1, l = 1;l <= n;l ++){
		while(r < n && x[r + 1] - x[l] <= d) ++r;
		suf[l] = r;
	}
	for(int j = 1;j <= n;j ++){
		for(int i = 0;i <= n + 1;i ++)
			f[i] = 0, g[i] = 0, dis[i] = 0;
		f[j] = 1;
		g[0] = 1;
		for(int i = j - 1, k = j; i ;i --){
			int r = min(j, suf[i]);
			dis[i] = dis[r] + 1;
			while(i < k && x[k] - x[i] > d) g[dis[k]] -= f[k], --k;
			if(dis[i] - 1 >= 0) f[i] += g[dis[i] - 1];
			
			if(f[i] == 2){
				ans++;
			}
			g[dis[i]] += f[i];
		}
	}
	cout << ans << "\n";
}

int pre[N], now;
void dfs(int u, int lst, int ky){
	if(u == lst && u != now) return ;
	int v = pre[u];
	if(!ky){
		if(v + 2 > u){
			dfs(v, u, 0);
			return ;
		}
		int a = pre[v], b = pre[v + 1], c = pre[v + 2];
		ans += max(0, c - b);
//		cout << u << " " << lst <<" "<< b << " " << c << "\n";
		if(a == b) ky = 1;
		if(ky && b == c) return ;
		dfs(v, u, ky);
		return ; 
	}
	if(v + 1 > u){
		dfs(v, u, 1);
		return ;
	}
	int a = pre[v], b = pre[v + 1];
	ans += max(0, b - a);
	dfs(v, u, 1);
	return ;
}

void work(){
	int n;
	LL d;
	ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;i ++)
		cin >> x[i];
	for(int r = 1, l = 1;r <= n;r ++){
		while(l < r && x[r] - x[l] > d) ++l;
		pre[r] = l;
		now = r;
		if(l != r) dfs(r, r, 0);
	}
	cout << ans << "\n";
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C, T;
	cin >> C >> T;
	while(T--){
		if(C <= 10) solve();
		else work();
	}
	return 0;
}
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
0 1
5 2
1 2 3 4 5
*/
