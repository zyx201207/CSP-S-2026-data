#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+1;
int c,n,m,d,Q;
ll w[N];
ll dis[505][505];
ll g[505][505];
pair<int,ll>que[N][21];
int cnt[N];
ll ans;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
vector<int>G[N];
void dijkstra(int s){
	q.push({0,s});
	pair<ll,int>now;
	int u;ll dir;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second,dir=now.first;
	//	cout<<s<<" "<<u<<" "<<dir<<"\n";
		if(dir!=dis[s][u]) continue;
		dis[u][s]=min(dis[u][s],dir);
		for(int v:G[u]){
			if(v==s) continue;
			if(dis[s][u]+g[u][v]<dis[s][v]){
				dis[s][v]=dis[s][u]+g[u][v];
				q.push({dis[s][v],v});
			}
		//	cout<<s<<" "<<u<<" "<<dis[s][u]<<" "<<v<<" "<<dis[s][v]<<" "<<g[u][v]<<"\n";
		}
	//	if(dis[s][u]>=dis[0][0]) cerr<<s<<" "<<u<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	memset(g,0x3f,sizeof(g));
	ll t;
	for(int i=1,k,a;i<=n;i++){
		dis[i][i]=g[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			for(int p=1;p<=cnt[a];p++){
				if(que[a][p].second+t<g[que[a][p].first][i])
					g[que[a][p].first][i]=1ll*que[a][p].second+t;
				if(que[a][p].second+t<g[i][que[a][p].first])
					g[i][que[a][p].first]=1ll*que[a][p].second+t;
			}
			cnt[a]++;
			que[a][cnt[a]]={i,t};
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(g[i][j]!=g[0][0]){
				G[i].push_back(j);
				G[j].push_back(i);
			}
//	for(int i=1;i<=n;i++)
//			if(g[i][j]!=g[0][0]) cout<<i<<" "<<j<<" "<<g[i][j]<<"\n";
	for(int i=1;i<=n;i++)
		dijkstra(i);
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<(dis[i][j]==dis[0][0]?-1:dis[i][j])<<" ";
		cout<<"\n";
	}*/
		
	int s;ll res;
	while(Q--){ 
		cin>>s>>t;
		ans=1e18;
		for(int i=1;i<=cnt[s];i++)
			for(int j=1;j<=cnt[t];j++){
				res=dis[que[s][i].first][que[t][j].first]+que[s][i].second+que[t][j].second;
	//			cerr<<que[s][i].first<<" "<<que[t][j].first<<" "<<res<<"\n";
				ans=min(ans,res);
			}
//		cerr<<ans<<" "<<w[s]<<" "<<w[t]<<"\n";
		cout<<(ans+w[s]+w[t])<<"\n";
	}
	return 0;
}

