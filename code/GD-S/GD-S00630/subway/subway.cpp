#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+7,S=507;
const ll inf=1e18;
int c,n,m,d,q,w[N],k,u,t,x,y;
ll dis[S][S],a[S][S],ans;
vector<pii > v[N];
priority_queue<pli > Q;
bool vis[N];
void dij(int s){
	Q.push({0,s});
	for(int i=1;i<=n;i++) vis[i]=0;
	while(!Q.empty()){
		int u=Q.top().se;
		ll d=-Q.top().fi;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=1,dis[s][u]=d;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[s][i]>dis[s][u]+a[u][i]){
				dis[s][i]=dis[s][u]+a[u][i];
				Q.push({-dis[s][i],i});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=a[i][j]=inf;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int l=1;l<=k;l++){
			cin>>u>>t;
			for(int j=0;j<v[u].size();j++){
				pii p=v[u][j];
				a[p.fi][i]=min(a[p.fi][i],(ll)t+p.se);
				a[i][p.fi]=a[p.fi][i];
			}
			v[u].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) dij(i);
	while(q--){
		cin>>x>>y,ans=inf;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,dis[v[x][i].fi][v[y][j].fi]+
				w[x]+w[y]+v[x][i].se+v[y][j].se);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
