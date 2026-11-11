#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qu,k[505],x,t,ans,u,v;
int w[500005],val[505][505],dist[505][505];
bool vis[505];
struct node{
	int id,t;
	bool operator <(const node&b)const{
		return t>b.t;
	}
};
vector<node> e[500005],g[505];
priority_queue<node> q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	memset(dist,0x3f3f,sizeof(dist));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>t;
			e[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		if(e[i].size()>1){
			for(int j=0;j<e[i].size();j++){
				for(int l=0;l<e[i].size();l++){
					if(e[i][j].id!=e[i][l].id){
						val[e[i][j].id][e[i][l].id]=e[i][j].t+e[i][l].t;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&val[i][j]!=0){
				g[i].push_back({j,val[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()) q.pop();
		for(int j=1;j<=n;j++) vis[j]=0;
		q.push({i,0});
		while(!q.empty()){
			node p=q.top();
			q.pop();
			vis[p.id]=1;
			for(auto j:g[p.id]){
				if(vis[j.id])continue;
				dist[i][j.id]=min(dist[i][j.id],dist[i][p.id]+j.t);
				q.push({j.id,dist[i][j.id]});
			}
		}
	}
	while(qu--){
		ans=1e17;
		cin>>u>>v;
		for(auto i:e[u]){
			for(auto j:e[v]){
				ans=min(ans,i.t+j.t+dist[i.id][j.id]);
			}
		}
		ans=ans+w[u]+w[v];
		cout<<ans<<"\n";
	}
}

