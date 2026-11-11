#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
#define inf 0x3f3f3f3f3f3f3f3f
int c,n,m,d,Q;
int dtz[500005];
struct xyj{
	int v;
	ll dis;
	bool operator<(const xyj& qw)const{
		return dis>qw.dis;
	}
};
int gs;
vector<xyj> r[501005];
priority_queue<xyj> q;
ll dis[501005];
ll dist[505][505];
void dij(int st){
	while(!q.empty()) q.pop();
	for(int i=1;i<=m+n;i++) dis[i]=inf;
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
//		cout<<q.top().v<<"\n";
		xyj ls=q.top();
		q.pop();
		if(dis[ls.v]<ls.dis) continue;
		int u=ls.v;
		for(int i=0;i<r[u].size();i++) if(dis[u]+r[u][i].dis<dis[r[u][i].v]){
			dis[r[u][i].v]=dis[u]+(ll)r[u][i].dis;
			q.push({r[u][i].v,dis[r[u][i].v]});
		}
	}
//	cout<<st<<"!\n";
}
void solve(){
	for(int i=1;i<=n;i++){
//		cout<<i<<"\n";
		dij(i+m);
		for(int j=1;j<=n;j++) dist[i][j]=dis[j+m];
//		cout<<"over\n";
	}
}
vector<pair<int,int> > rd[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>dtz[i];
	gs=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		gs++;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			rd[a].push_back({i,t});
			r[a].push_back({gs,t});
			r[gs].push_back({a,t});
		}
	}
	if(1ll*n*(n+m)<=50000000){
		solve();
	}
	else{
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=(i==j?0:inf);
		for(int i=1;i<=m;i++){
			for(int j=0;j<rd[i].size();i++) 
				for(int l=j+1;l<rd[i].size();l++){
					int u=rd[i][j].first;
					int v=rd[i][l].first;
					dist[u][v]=dist[v][u]=min(dist[u][v],(ll)rd[i][j].second+(ll)rd[i][l].second);
				}
		}
		for(int k=1;k<=n;k++) 
			for(int i=1;i<=n;i++) if(i!=k&&dist[i][k]<inf)
				for(int j=i+1;j<=n;j++) if(j!=k&&dist[j][k]<inf){
					dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[j][k]);
				}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<rd[x].size();i++)
			for(int j=0;j<rd[y].size();j++){
				ans=min(ans,(ll)rd[x][i].second+(ll)rd[y][j].second+dist[rd[x][i].first][rd[y][j].first]);
			}
		cout<<ans+(ll)dtz[x]+(ll)dtz[y]<<"\n";
	}	
	return 0;
}

