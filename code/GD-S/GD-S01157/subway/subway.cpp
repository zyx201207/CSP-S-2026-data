#include <bits/stdc++.h>
#define fs first
#define sc second
#define int long long
#define vi vector<int> 
#define For(i,x,y) for(int i = x;i <= y;i ++)
#define For_(i,x,y) for(int i = x;i <= y;i ++)
#define pb push_back
#define endl '\n'
#define x0 _x0_
#define y1 _y1_
#define pii pair<int,int> 
const int N = 5e5 + 5,M = 505;
const int linf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
void gmax(int &x,int y) {
	x = max(x,y);
	return ;
}void gmin(int &x,int y) {
	x = min(x,y);
	return ;
}int c,n,m,d,q;
int w[N];
int dis[M][M];
vector<pii> vec[N];
void solve(){
	cin >> c >> n >> m >> d >> q;
	For(i,1,m) cin >> w[i];
	For(i,1,n) {
		int k;cin >> k;
		For(j,1,k) {
			int a,t;cin >> a >> t;
			vec[a].pb({i,t});
		}
	}memset(dis,0x3f,sizeof dis);
	For(i,1,n) dis[i][i] = 0; 
	For(i,1,m) {
		for(auto it:vec[i]) {
			for(auto it2:vec[i]) {
				gmin(dis[it.fs][it2.fs],it.sc+it2.sc);
				gmin(dis[it2.fs][it.fs],it.sc+it2.sc);
			}
		}
	}For(k,1,n) For(i,1,n) For(j,1,n) {
		gmin(dis[i][j],dis[i][k] + dis[k][j]);
	}For(i,1,q) {
		int u,v;
		cin >> u >> v;
		int ans = linf;
		for(auto it : vec[u]) for(auto it2 : vec[v]) {
			gmin(ans,it.sc + it2.sc + dis[it.fs][it2.fs]);
		}cout << ans + w[u] + w[v] << endl;
	}
}signed main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T = 1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
//	cin >> T;
	while(T--) solve();
	return 0;
}
