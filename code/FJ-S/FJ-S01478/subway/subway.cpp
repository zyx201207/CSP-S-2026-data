#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=510;
const int M=5e5+10;
int w[M];
int dis[M+N];
int mp[M];
int c,n,m,d,q;
vector<PII>G[M+N];
int dij(int st,int ed){
	for(int i=1;i<=m+n;i++){
		dis[i]=1e9;
	}
	map<int,bool>vis[M+N];
	priority_queue<PII,vector<PII>,greater<PII>>q;
	vis[0][st]=1;
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int u=t.second;
		for(PII &i:G[u]){
			int v=i.first;
			int w=i.first;
			if(dis[u]+w<dis[v]&&!vis[v][u]){
				dis[v]=dis[u]+w;
				vis[v][u]=1;
				q.push({dis[v],v});
			}
		}
	}
	return dis[ed];
}
int main(){
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
			G[m+i].push_back({a,t});
			G[a].push_back({m+i,t});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+dij(u,v)<<"\n";
	}
	return 0;
}
