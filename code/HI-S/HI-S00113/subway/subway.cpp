#include<bits/stdc++.h>
using namespace std;
int c,d,n,m,q;
int w[500005],vis[500005],dis[500005];
struct node{
	int num,dis;
	bool operator < (const node &b) const{
	     return dis<b.dis;
	}
};

vector<node> mp[50006];
void dij(int u,int v){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	vis[u]=1;
	dis[u]=0;
	priority_queue<node> q;
	q.push({u,0});
	while(!q.empty()){
		node c=q.top();
		q.pop();
		if(vis[c.num]) continue;
		vis[c.num]=1;
		for(int i=0;i<mp[c.num].size();i++){
			int vv=mp[c.num][i].num,ww=mp[c.num][i].dis;
			if(dis[vv]>dis[c.num]+ww){
				dis[vv]=dis[c.num]+ww;
				if(!vis[vv]) q.push({vv,dis[vv]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		mp[i].push_back({i+m,w[i]});
		mp[i+m].push_back({i,w[i]});//i+m kou
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;
			cin>>x>>w;
			mp[x].push_back({i+2*m,w});
			mp[i+2*m].push_back({x,w});//i+2*m tai
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dij(u+m,v+m);
		cout<<dis[v+m]<<'\n';
	}
	return 0;
}
