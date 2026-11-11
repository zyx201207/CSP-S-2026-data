#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int> 
bool vis[505];
ll dis[505][500];
vector<pii> e[550005];
vector<int> f[550005];
void dij(int x){
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,x});
	dis[x][x]=0;
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int u=t.second;
		vis[u]=1;
		for(pii o:e[u]){
			int v=o.first,w=o.second;
			if(vis[v]) continue;
			if(dis[x][u]+w<dis[x][v]){
				dis[x][v]=dis[x][u]+w;
				q.push({dis[x][v],v});
			}
		}
	}
}
int c,n,m,d,q;
int w[500005],t[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,127,sizeof(dis));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,x[500005];i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j];
			f[x[j]].push_back(i);
			cin>>t[i][x[j]];
		}
	}
	for(int i=1;i<=m;i++)
		for(int j:f[i]){
			for(int k:f[i]){
				if(j!=k){
					e[j].push_back({k,t[j][i]+t[k][i]});
					e[k].push_back({j,t[j][i]+t[k][i]});
				}
			}
		}
	for(int i=1;i<=n;i++) dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll mn=1145141919810;
		for(int j:f[x]){
			for(int k:f[y]){
				mn=min(mn,t[j][x]+t[k][y]+dis[j][k]);
			}
		}
		cout<<w[x]+w[y]+mn<<'\n';
	}
}
