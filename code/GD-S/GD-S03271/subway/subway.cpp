#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,INF=1e9;
int c,n,m,d,q,x,y,w[N],k[505],a[505][505],t[505][505],ans=INF;
vector<int>s[N];
map<int,pair<int,int>>mp;
void bfs(int st,int des){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<bool>vis(n,0);
	pq.push({w[x],x});
	vis[st]=1;
	while(pq.size()){
		auto [u,v]=pq.top();
		pq.pop();
		int l=s[u].size();
		for(int i=0;i<l;i++){
			for(int j=1;j<=k[s[u][i]];j++){
				if(a[s[u][i]][j]==y){
						ans=min(ans,v+t[s[u][i]][u]+t[s[u][i]][y]+w[y]);
						return;
				}if(!vis[s[u][i]]){
					vis[s[u][i]]=1;
					pq.push({v+t[s[u][i]][u]+t[s[u][i]][a[s[u][i]][j]]+w[a[s[u][i]][j]],s[u][i]});
				}
			}
		}
	}
}
void find(int x,int y){
	int l=s[x].size();
	vector<int>dist(n,INF);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dist[x]=w[x];
	pq.push({dist[x],x});
	while(!pq.empty()){
		auto dpos=pq.top();
		pq.pop();
		int pos=dpos.second;
		for(int i=0;i<l;i++){
			for(int j=1;j<=k[s[pos][i]];j++){
				if(a[s[pos][i]][j]==y){
					dist[y]=w[pos]+t[s[pos][i]][pos]+t[s[pos][i]][y]+w[y];
					ans=min(ans,dist[y]);
					return;
				}else if(dist[a[s[pos][i]][j]]==INF){
					dist[a[s[pos][i]][j]]=min(dist[a[s[pos][i]][j]],dist[pos]+t[s[pos][i]][pos]
					+t[s[pos][i]][a[s[pos][i]][j]]+w[a[s[pos][i]][j]]);
					pq.push({dist[a[s[pos][i]][j]],a[s[pos][i]][j]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			s[a[i][j]].push_back(i);
		}
	}while(q--){
		cin>>x>>y;
		bfs(x,y);
		cout<<ans<<endl;
	}
}
