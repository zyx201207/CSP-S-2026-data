#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct tututu{int v,w;};
vector<tututu> mapp[550005];
int w[505];
int dis[550005];bool vis[550005];
int dij(int u,int v){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int> >q;
	memset(vis,0,sizeof vis);
	dis[u]=0;
	q.push({0,u});
	while (!q.empty()){
		int uu=q.top().second;q.pop();
		if (vis[uu]) continue;
		vis[uu]=1;
		for (tututu vv:mapp[uu]) {
			int to=vv.v,w=vv.w;
			if (dis[uu]+w<=dis[to]) {
				dis[to]=dis[uu]+w;
				q.push({-dis[to],to});
			}
		}
	}
	return dis[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int k;cin>>k;
		int lst=-1;
		for (int j=1;j<=k;j++){
			int z,t;cin>>z>>t;
			mapp[i+m].push_back({z,t});
			mapp[z].push_back({i+m,t});
			if (lst==-1) {
				lst=z;
				continue;	
			}
//			mapp[i*m+z].push_back({i*m+lst,0});
//			mapp[i*m+lst].push_back({i*m+z,0});
			lst=z;
		}
	}
//			for (int i=1;i<=n*m;i++){
//			for (auto v:mapp[i]) cout<<v.v<<" ";
//			cout<<"\n";
//		}
	while (q--){
		int u,v;cin>>u>>v;
		cout<<dij(u,v)+w[u]+w[v]<<"\n";
	}
	return 0;
}

