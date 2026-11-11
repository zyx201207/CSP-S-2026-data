#include <bits/stdc++.h>
using namespace std;
struct Node{
	int to;
	long long w;
	bool operator<(const Node& other)const{
		return w<other.w;
	}
};
vector<Node>g[500510];
int w[500010];
vector<pair<int,int>>p[500010];
int k[510],a[500010],t[500010];
long long dis[500510];
long long ans[100010];
int c,n,m,d,q,cnt=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			g[a[j]].push_back({m+i,t[j]});
			g[m+i].push_back({a[j],t[j]});
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		if(u>v)swap(u,v);
		p[u].push_back({v,i});
	}
	for(int i=1;i<=m;i++){
		if(!p[i].size())continue;
		memset(dis,0x3f,sizeof(dis));
		dis[i]=0;
		priority_queue<Node>q;
		q.push({i,0});
		while(!q.empty()){
			int u=q.top().to,uw=q.top().w;
			q.pop();
			if(uw>dis[u])continue;
			for(int j=0,v,w;j<g[u].size();j++){
				//cout<<"/"; 
				v=g[u][j].to,w=g[u][j].w;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.push({v,dis[v]});
				}
			}
		}
		for(int j=0;j<p[i].size();j++){
			int v=p[i][j].first,id=p[i][j].second;
			ans[id]=w[i]+w[v]+dis[v];
			cnt++;
		} 
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
