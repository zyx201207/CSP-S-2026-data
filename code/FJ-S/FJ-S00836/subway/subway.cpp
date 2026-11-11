#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+10;
int n,m,d,q,T;
ll w[N],tim;
struct node{
	ll v,w;
};
vector<node> e[N*3];
void add(int u,int v,int w){
	e[u].push_back({v,w});
}
ll dis[1010][1010],ds[N*3];
ll diss[N*3];
bool vis[N*3];
void dij(int s){
	priority_queue<pair<int,int> > q;
	for(int i=1;i<=tim;i++){
		vis[i]=0,ds[i]=1e18;
	}
	q.push(make_pair(0,s));
	ds[s]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v,w=e[u][i].w;
			if(ds[v]>ds[u]+w){
				ds[v]=ds[u]+w;
				q.push(make_pair(-ds[v],v));
			}
		}
	}
	for(int i=1;i<=m;i++){
		dis[s][i]=ds[i];
	}
}
void bfs(int s){
	deque<int> q;
	for(int i=1;i<=tim;i++){
		vis[i]=0,diss[i]=1e18;
	}
	q.push_back(s);
	diss[s]=0;
	while(q.size()){
		int u=q.front();
		q.pop_front();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v,w=e[u][i].w;
			if(diss[v]>diss[u]+w){
				diss[v]=diss[u]+w;
				if(w==0)q.push_front(v);
				else q.push_back(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	tim=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++){
			int u,val;
			cin>>u>>val;
			++tim;
			add(u,tim,val);
			add(tim,u,val);
			if(j>1)add(lst,tim,0),add(tim,lst,0);
			lst=tim;
		}
	}
	if(T>=12&&T<=15){
		while(q--){
			int u,v;
			cin>>u>>v;
			bfs(u);
			cout<<w[u]+w[v]+diss[v]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<'\n';
	}
	return 0;
}
