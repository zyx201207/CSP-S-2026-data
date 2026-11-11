#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M];
ll dis[N][N];
ll a[N][N];
vector<pii> G[M+N];
vector<int> line[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			a[i][j]=dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			for(int l=0;l<G[u].size();l++){
				int pos=G[u][l].first,dist=G[u][l].second;
				if(a[pos][i]<=dist+v)continue;
				a[pos][i]=a[i][pos]=dist+v;
			}
			G[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		priority_queue<pii> q;
		q.push({i,0});
		while(q.size()){
			int u=q.top().first;
			q.pop();
			for(int v=1;v<=n;v++){
				if(a[u][v]+dis[i][u]<dis[i][v]){
					dis[i][v]=a[u][v]+dis[i][u];
					q.push({v,-dis[i][v]});
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(int i=0;i<G[u].size();i++){
			for(int j=0;j<G[v].size();j++){
				int pos1=G[u][i].first;
				int dist1=G[u][i].second;
				int pos2=G[v][j].first;
				int dist2=G[v][j].second;
				ans=min(ans,dis[pos1][pos2]+dist1+dist2);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}
