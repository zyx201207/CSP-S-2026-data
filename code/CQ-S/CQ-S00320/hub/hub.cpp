//
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<int, int>
#define fs first
#define se second
#define lp p * 2
#define rp p * 2 + 1
#define pb push_back
#define all(s) s.begin(), s.end()
#define db double
#define i128 __int128
#define Mid auto mid = (l + r) / 2
using namespace std;
template<class T1, class T2>
void cmax(T1 &a, T2 b){if(a < b)a = b;}
template<class T1, class T2>
void cmin(T1 &a, T2 b){if(a > b)a = b;}
template<class T>
void read(T &x){
	int k = 0;
	char c = getchar();
	while(!isdigit(c))c = getchar();
	while(isdigit(c))k = k * 10 + c - 48, c = getchar();
	x = k;
}
const int N = 1145;
int n, k;
vector<int>g[N];
int ans = 0;
int col[N];
int dis[N][N];
bool vis[N];
void ddd(int u, int bg, int d){
	dis[bg][u] = d;
	vis[u] = 1;
	for(auto e : g[u]){
		if(!vis[e]){
			ddd(e, bg, d + 1);
		}
	}
}
void dfs(int u){
	vis[u] = 1;
	for(auto e : g[u]){
		if(col[e] && !vis[e]){
			dfs(e);
		}
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		g[i].clear();
		for(int j = 1; j <= n; j ++){
			dis[i][j] = 1e17;
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i < n; i ++){
		int a, b; cin >> a >> b;
		g[a].pb(b); g[b].pb(a);
	}
	for(int i = 1; i <= n; i ++){
		memset(vis, 0, sizeof vis);
		ddd(i, i, 0);
	}
	ans = 1e18;
	if(k == 2){
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				int mx = 0;
				for(int w = 1; w <= n; w ++){
					cmax(mx, min(dis[i][w], dis[j][w]));
				}
				cmin(ans, mx);
			}
		}
		cout << ans << "\n";
		return ;
	}
	for(int i = 1; i < (1 << n); i ++){
		int cnt = 0, res = 0;
		for(int j = 1; j <= n; j ++){
			col[j] = (i >> (j - 1) & 1);
			cnt += col[j];
		}
		if(cnt != k){
			continue;
		}
		memset(vis, 0, sizeof vis);
		for(int j = 1; j <= n; j ++){
			if(!vis[j] && col[j]){
				res ++;
				dfs(j);
			}
		}
		if(res > 2){
			continue;
		}
//		if(i == 9){
//			cerr << "!!!!!\n";
//		}
		int mx = 0;
		for(int j = 1; j <= n; j ++){
//			if(i == 9){
//				cerr << col[j] << " ";
//			}
			if(col[j])continue;
			int mn = 1e9;
			for(int w = 1; w <= n; w ++){
				if(col[w]){
					cmin(mn, dis[j][w]);
				}
			}
//			if(i == 9){
//				cerr << j << " " << mn << "\n";
//			}
			cmax(mx, mn);
		}
		cmin(ans, mx);
	}
	cout << ans << "\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T = 1;
	cin >> T >> T;
	while(T --){
		solve();
	}
}
/*
luogu : bugaboost114514
Oct31==Dec25?
*/

