#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+10;
int c,n,m,d,q;
int cz[M],vis[N];
vector<pair<int,int>>vec[M];
int f[N][N];
priority_queue<pair<int,int>>pq;
vector<pair<int,int>>edge[N];
void add(int u,int v,int w){
	edge[u].push_back({v,w});
	edge[v].push_back({u,w});
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>cz[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++)for(int k=j+1;k<vec[i].size();k++){
			int x=vec[i][j].first;
			int y=vec[i][k].first;
			int w=vec[i][j].second+vec[i][k].second;
			add(x,y,w);
		}
	}
	for(int i=1;i<=n;i++){
		while(!pq.empty())pq.pop();
		for(int j=0;j<N;j++)vis[j]=0,f[i][j]=LLONG_MAX/2;
		f[i][i]=0;
		pq.push({0,i});
		while(!pq.empty()){
			auto k=pq.top();
			pq.pop();
			int u=k.second;
			for(int j=0;j<edge[u].size();j++){
				int v=edge[u][j].first;
				int w=edge[u][j].second;
				if(f[i][v]<=f[i][u]+w)continue;
				vis[v]=1;
				f[i][v]=f[i][u]+w;
				pq.push({-f[i][v],v});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=LLONG_MAX;
		for(int i=0;i<vec[x].size();i++)for(int j=0;j<vec[y].size();j++){
			int u=vec[x][i].first;
			int v=vec[y][j].first;
			int wu=vec[x][i].second;
			int wv=vec[y][j].second;
			minn=min(minn,f[u][v]+wu+wv);
		}
		int ans=minn+cz[x]+cz[y];
		cout<<ans<<"\n";
	}
	return 0;
}
//zmh GD-S01968
