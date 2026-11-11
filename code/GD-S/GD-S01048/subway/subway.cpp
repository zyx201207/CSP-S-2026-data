#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e6+10;
int w[N];
int c,n,m,d,q;
vector<pii>e[N];
int vis[N];
int dis[N];
int djs(int x,int y){
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({x,0});
	dis[x]=0;
	while(q.size()){
		pii p=q.top();
		q.pop();
		int u=p.first,ds=p.second;
		if(vis[u]==1)continue;
		else vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,w=e[u][i].second;
			if(dis[v]>ds+w){
				dis[v]=ds+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[y]+w[x]+w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<djs(x,y)<<"\n";
	}
	return 0;
} 
