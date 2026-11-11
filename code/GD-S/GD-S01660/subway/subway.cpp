#include <bits/stdc++.h>
using namespace std;
#define pa pair<int,ll>
#define fi first
#define sc second
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define REP(i,x,y) for(int i=(x);i>=(y);i--)
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
const int M=500003;
const int N=503;
const ll INF=1e18;
int testId,n,m,D,Q;
ll a[M],dis[N][N];
vector<pa> v[M];
void FLoyd(){
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	fastIO;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>testId>>n>>m>>D>>Q;
	rep(i,1,m) cin>>a[i];
	int x,y; ll z;
	rep(i,1,n){
		cin>>x;
		while(x--){
			cin>>y>>z;
			v[y].push_back({i,z});
		}
	}
	rep(i,1,n) rep(j,1,n){
		if(i==j) dis[i][j]=0;
		else dis[i][j]=INF;
	}
	rep(i,1,m){
		rep(j,0,(int)v[i].size()-2){
			rep(k,j+1,(int)v[i].size()-1){
				x=v[i][j].fi;
				y=v[i][k].fi;
				z=v[i][j].sc+v[i][k].sc;
				dis[x][y]=min(dis[x][y],z);
				dis[y][x]=min(dis[y][x],z);
			}
		}
	}
	FLoyd(); ll ans;
	while(Q--){
		cin>>x>>y;
		ans=INF;
		rep(i,0,(int)v[x].size()-1){
			rep(j,0,(int)v[y].size()-1){
				ans=min(ans,v[x][i].sc+dis[v[x][i].fi][v[y][j].fi]+v[y][j].sc);
			}
		}
		ans+=a[x]+a[y];
		cout<<ans<<"\n";
	}
	return 0;
}
