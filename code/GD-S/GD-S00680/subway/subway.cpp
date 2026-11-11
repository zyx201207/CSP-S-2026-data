#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],dist[500010],a[510],t[510];
struct st{
	int to,val;
};
vector<vector<st> > edge;
void bfs(int u1){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,u1));
	dist[u1]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		int sl=edge[u].size();
		for(int j=0;j<sl;j++){
			//cout<<1;
			int v=edge[u][j].to,w=edge[u][j].val;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				//cout<<"u:"<<u<<" v:"<<v<<" dist[v]:"<<dist[v]<<'\n';
				q.push(make_pair(dist[v],v));
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	edge.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int nn;
		cin>>nn;
		//cout<<i<<' '<<nn<<'\n';
		for(int j=1;j<=nn;j++) cin>>a[j]>>t[j];
		for(int k=1;k<=nn;k++){
			for(int j=1;j<=nn;j++){
				if(k!=j){
					st tt;
					tt.to=a[j],tt.val=t[k]+t[j];
					edge[a[k]].push_back(tt);
					//cout<<a[k]<<' '<<a[j]<<' '<<tt.val<<'\n';
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(dist,0x3f3f3f3f,sizeof(dist));
		bfs(x);
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
