#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int w[500005];
vector<pii> G[500005];
vector<pii> to[505];
long long dis[505][505];
int tag[500005];
vector<int> used;
long long f[505][200005];
pii q[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			G[v].push_back({i,w});
			to[i].push_back({v,w});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto k1:G[i]){
			for(auto k2:G[i]){
				int x=k1.first,y=k2.first;
				long long w=k1.second+k2.second; 
				if(x==y) continue;
				dis[x][y]=min(dis[x][y],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=Q;i++){
		cin>>q[i].first>>q[i].second;
		tag[q[i].first]=tag[q[i].second]=1;
	}
	used.push_back(0);
	for(int i=1;i<=m;i++){
		if(tag[i]){
			used.push_back(i);
			tag[i]=used.size()-1;
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		for(auto k:to[i]){
			int u=k.first;
			long long w=k.second;
			if(tag[u]) f[i][tag[u]]=min(f[i][tag[u]],w);
		}
	}
//	for(int k=1;k<used.size();k++){
//		int i=used[k];
//		for(int u=1;u<=n;u++){
//			cout<<u<<' '<<i<<' '<<f[u][k]<<'\n';
//		}
//	}
	for(int i=1;i<used.size();i++){
		int k=used[i];
//		cout<<i<<' '<<k<<'\n';
		for(auto t:G[k]){
			int u=t.first;
			long long w=t.second;
//			cout<<u<<' '<<i<<' '<<'\n';
			for(int v=1;v<=n;v++) f[v][i]=min(f[v][i],w+dis[u][v]);
		}
	}
//	for(int k=1;k<used.size();k++){
//		int i=used[k];
//		for(int u=1;u<=n;u++){
//			cout<<u<<' '<<i<<' '<<f[u][k]<<'\n';
//		}
//	}
	for(int i=1;i<=Q;i++){
		int s=tag[q[i].first],t=tag[q[i].second];
		long long ans=1e18;
		for(int u=1;u<=n;u++){
			ans=min(ans,f[u][s]+f[u][t]);
		}
		cout<<ans+w[q[i].first]+w[q[i].second]<<'\n';
	}
}

