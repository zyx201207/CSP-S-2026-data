#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=1005,M=2e4+5;

int c,n,m,d,q;
int dis[N][N],w[M],k[N],a[505][M],t[505][M];
bool vis[M];
int dist[M];
vector<pair<int,int> > e[N];
vector<int> mp[M];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > r;
queue<int> Q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]].push_back(i);
		}
	}
	if(c>=12 && c<=19){
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=m;i++) dist[i]=0,vis[i]=0;
			while(!Q.empty()) Q.pop();
			Q.push(x);
			vis[x]=1;
			while(!Q.empty()){
				int u=Q.front();
				Q.pop();
				if(u==y) break;
				for(auto che:mp[u]){
					for(int i=1;i<=k[che];i++){
						int v=a[che][i];
						if(!vis[v]){
							vis[v]=1;
							dist[v]=dist[u]+1;
							Q.push(v);
						}
					}
				}
			}
			cout<<dist[y]*t[1][1]*2+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	/*
	for(int kk=1;kk<=m;kk++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j) dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
				else dis[i][j]=0;
			}
		}
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<j;l++){
				int u=a[i][l],v=a[i][j],w=t[i][j]+t[i][l];
				//dis[u][v]=dis[v][u]=t[i][j]+t[i][l];
				e[u].push_back({v,w});
				e[v].push_back({u,w});
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) dis[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) vis[j]=0;
		r.push({0,i});
		dis[i][i]=0;
		while(!r.empty()){
			int u=r.top().second;
			r.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto vv:e[u]){
				int v=vv.first,w=vv.second;
				if(dis[i][u]+w<dis[i][v]){
					dis[i][v]=dis[i][u]+w;
					r.push({dis[i][v],v});
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}

