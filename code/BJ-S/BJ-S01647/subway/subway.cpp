#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=20005;
const int REQ=1e5+10;
struct edge{
	int to;
	ll weight;
};

struct dian{
	int u;
	ll weight;
	bool operator > (const dian tmp) const{
		return weight>tmp.weight;
	}
};

int C,n,m,d,q;
ll val[N];
vector <edge> e[N];
vector <ll> lu[505],luv[505];

bool vis[N];
ll dis[N];
priority_queue < dian,vector<dian>,greater<dian> > qq;
int req1[REQ],req2[REQ],ccnt[N];
vector <ll> ans[N];

void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	qq.push({st,0});
	int u,v,w;
	while(!qq.empty()){
		u=qq.top().u;
		if(vis[u]) continue;
		dis[u]=min(dis[u],qq.top().weight);
		qq.pop();
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			v=e[u][i].to,w=e[u][i].weight;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				qq.push({v,dis[v]});
			}
		}
	}
	while(!qq.empty()) qq.pop();
	ans[st].push_back(0);
	for(int i=1;i<=m;i++){
		ans[st].push_back(dis[i]);
		//cout<<dis[i]<<endl;
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		int sz,u,w;
		cin>>sz;
		for(int j=1;j<=sz;j++){
			cin>>u>>w;
			lu[i].push_back(u),luv[i].push_back(w);
		}
		for(int j=0;j<=sz-1;j++){
			for(int k=0;k<j;k++){
				e[lu[i][j]].push_back( { lu[i][k] , luv[i][j]+luv[i][k] } );
				e[lu[i][k]].push_back( { lu[i][j] , luv[i][j]+luv[i][k] } );
			}
			
		}
	}
	/*
	for(int i=1;i<=m;i++){
		cout<<i<<endl;
		for(auto tmp :e[i]){
			cout<<tmp.to<<" "<<tmp.weight<<endl;
		}
	}
	*/
	//dij(1);
	int u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ccnt[u]++;
		req1[i]=u,req2[i]=v;
	}
	for(int i=1;i<=m;i++){
		if(ccnt[i]!=0) dij(i);
	}
	ll tans;
	for(int i=1;i<=q;i++){
		tans=ans[req1[i]][req2[i]]+val[req1[i]]+val[req2[i]];
		cout<<tans<<'\n';
	}
	return 0;
}
