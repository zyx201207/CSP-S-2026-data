#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const ll INF = 1e16;
const int N = 5e5+15;
const int M = 505;
int c,n,m,d,q;

vector< pair<int,ll> >v[N];
ll w[N];
ll e[M][M];
ll ans;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;++i)for(int j = 1;j <= n;++j)e[i][j]=INF;
	for(int i = 1;i <= n;++i)e[i][i]=0;
	
	for(int i = 1;i <= m;++i)cin >> w[i];
	int T;
	int x,y;
	for(int i = 1;i <= n;++i){
		cin >> T;
		if(T==1)continue;
		while(T--){
			cin >> x >> y;
			v[x].push_back({i,y});
		}
	}
	for(int u = 1;u <= m;++u){
		for(int j = 0;j < v[u].size();++j){
			x = v[u][j].fi;
			for(int k = j+1;k < v[u].size();++k){
				y = v[u][k].fi;
				e[x][y] = e[y][x] = min(e[x][y],v[u][j].se + v[u][k].se);
			}
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			if(i==j)continue;
			for(int k = j+1;k <= n;++k){
				e[j][k] = e[k][j] = min(e[j][i]+e[i][k],e[j][k]);
			} 
		}
	}
	while(q--){
		cin >> x >> y;
		ans = INF;
		for(int j = 0;j < v[x].size();++j){
			for(int k = 0;k < v[y].size();++k){
				ans = min(ans,e[v[x][j].fi][v[y][k].fi]+v[x][j].se+v[y][k].se);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
