#include<bits/stdc++.h>
#define int long long
#define pip pair<int,pair<int,int>>
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q;
int w[2005];
int k[505];
int t[505][2005];
vector<pii> e[2005];
vector<int> mp[2005];
priority_queue<pip,vector<pip>,greater<pip>> qq;
int dist[2005][505];
map<pii,int> mpp;
int x,y;
int dij(int st,int op){
	memset(dist,0x3f,sizeof(dist));
	qq.push({0,{st,op}});
	dist[st][op]=0;
	while(!qq.empty()){
		int u=qq.top().second.first;
		int id=qq.top().second.second;
		qq.pop();
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first;
			int idx=e[u][i].second;
			int add=0;
			if(idx!=id){
				add=t[id][u]+t[idx][u];
			}
			if(v==y){
				if(dist[v][idx]>dist[u][id]+add+t[idx][v]){
					dist[v][idx]=dist[u][id]+add+t[idx][v];
					qq.push({dist[v][idx],{v,idx}});
				}
			}
			else if(dist[v][idx]>dist[u][id]+add){
				dist[v][idx]=dist[u][id]+add;
				qq.push({dist[v][idx],{v,idx}});
			}
		}
	}
	int minx=1145141919810;
	for(int i=1;i<=n;i++){
		minx=min(minx,dist[y][i]);
	}
	return minx;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int u,tt,preu,fi;
		for(int j=1;j<=k[i];j++){
			cin>>u>>tt;
			if(j==1){
				fi=u;
			}
			t[i][u]=tt;
			if(j!=1){
				e[preu].push_back({u,i});
			}
			mp[u].push_back(i);
			preu=u;
		}
		e[preu].push_back({fi,i});
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int minn=1145141919810;
		for(auto v:mp[x]){
			minn=min(minn,dij(x,v)+w[x]+w[y]+t[v][x]);
		}
		cout<<minn<<"\n";
	}
	return 0;
} 
