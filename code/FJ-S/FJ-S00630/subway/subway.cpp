#include<bits/stdc++.h>
using namespace std;
long long g[405][405];
long long h[405][405];
priority_queue<pair<long long,long long>, vector<pair<long long,long long> >, greater<pair<long long,long long> > > q;
long long c,n,m,d,qq,k;
long long w[500005];
long long a;
long long uo[405][405];
long long t[500005][25];
long long cnt[500005]; 
long long js[500005],jss[500005];
bool flag[500005];
long long dis[500005];
/*long long diskstra(long long s,long long f){
	while(!q.empty())q.pop();
	q.push({s,0});
	for(long long i=0;i<=n;i++){
		flag[i]=0;
		dis[i]=1e18;
	}
	while(!q.empty()){
		//cout<<1<<'\n';
		long long u=q.top().second;
		q.pop();
		if(flag[u])continue;
		flag[u]=1;
		long long m=g[u].size();
		long long v,w;
		for(long long i=0;i<m;i++){
			v=g[u][i].second;
			w=g[u][i].first;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[f];
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			g[i][j]=1e18;
			uo[i][j]=1e18;
		}
	}
	
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	long long lst;
	for(long long i=1;i<=n;i++){
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a;
			if(j!=1){
				//g[a].push_back({0,lst});
				
			}
			lst=j;
			cin>>uo[a][i];
			uo[i][a]=uo[a][i];
			
		}
		
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				
				g[i][j]=min(uo[i][k]+uo[k][j],g[i][j]);
				
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j){
					continue;
				}
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	long long x,y;
	while(qq--){
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
