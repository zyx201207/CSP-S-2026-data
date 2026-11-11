#include <bits/stdc++.h>
using namespace std;
#define M 500005
#define ll long long
#define N 505
#define pi pair<int,int>
#define fi first
#define se second
#define inf 1000000000000000000LL
int c,n,m,D,q,w[M];
vector<pi >g[M];
ll d[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1;i <= m;++i) cin >> w[i];
	//return 0;
	for(int i = 1,K,a,t;i <= n;++i){
		cin >> K;
		//if(K == 0) continue;
		while(K--){
			cin >> a >> t;
			g[a].push_back((pi){i,t});
		}
	}
	//return 0;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j) d[i][j] = inf;
		d[i][i] = 0LL;
	}
	
	for(int i = 1,sz;i <= m;++i){
		sz = (int)g[i].size();
		if(sz <= 1) continue;
		for(int j = 0,x,t1;j < sz-1;++j){
			x = g[i][j].fi,t1 = g[i][j].se;
			for(int k = j+1,y,t2;k < sz;++k){
				y = g[i][k].fi,t2 = g[i][k].se;
				d[x][y] = min(d[x][y],(ll)t1+(ll)t2);
				d[y][x] = min(d[y][x],(ll)t1+(ll)t2);
			}
		} 
	}
	for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			if(i == k || d[i][k] >= inf) continue;
			for(int j = 1;j <= n;++j){
				if(i == j || k == j || d[k][j] >= inf) continue;
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i = 1,a,b,sz1,sz2;i <= q;++i){
		cin >> a >> b;
		ll ans = inf;
		sz1 = (int)g[a].size(),sz2 = (int)g[b].size();
		for(int j = 0,x,t1;j < sz1;++j){
			x = g[a][j].fi,t1 = g[a][j].se;
			for(int k = 0,y,t2;k < sz2;++k){
				y = g[b][k].fi,t2 = g[b][k].se;
				ans = min(ans,(ll)t1+(ll)t2+d[x][y]);
			}
		}
		ans += w[a] + w[b];
		cout << ans << '\n'; 
	}
	return 0;
}
