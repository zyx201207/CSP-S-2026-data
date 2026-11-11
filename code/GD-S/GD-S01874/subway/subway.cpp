#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+50,INF=1e18;
int id,n,m,d,Q;
int cost[M],sz[M];
struct edge{
	int to,w;
};
vector<edge> e[M];
int g[N][N],dis[N][N];
priority_queue<pair<int,int> >q;
void dij(int s){
	while(!q.empty())
		q.pop();
	dis[s][s]=0;
	q.push({0,s});
	for(int i=1;i<s;i++){
		dis[s][i]=dis[i][s];
		q.push({-dis[i][s],i});
	}
	while(!q.empty()){
		int x=q.top().second,d=-q.top().first;
		q.pop();
		if(d!=dis[s][x])
			continue;
		for(int i=1;i<=n;i++){
			if(g[x][i]==INF)
				continue;
			if(dis[s][i]>dis[s][x]+g[x][i]){
				dis[s][i]=dis[s][x]+g[x][i];
				q.push({-dis[s][i],i});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>cost[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y});
			sz[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=g[i][j]=INF;
	for(int i=1;i<=m;i++)
		for(int j=0;j<sz[i];j++)
			for(int k=j+1;k<sz[i];k++){
				int x=e[i][j].to,y=e[i][k].to;
				int w1=e[i][j].w,w2=e[i][k].w;
				g[x][y]=g[y][x]=min(g[x][y],w1+w2);
			}
	for(int i=1;i<=n;i++)
		dij(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<' ';
//		cout<<"\n";
//	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(int i=0;i<sz[x];i++)
			for(int j=0;j<sz[y];j++){
				int s1=e[x][i].to,s2=e[y][j].to;
				if(dis[s1][s2]==INF)
					continue;
				int w1=e[x][i].w,w2=e[y][j].w;
//				cout<<w1<<' '<<w2<<' '<<dis[s1][s2]<<"\n";
				ans=min(ans,dis[s1][s2]+w1+w2);
			}
		cout<<ans+cost[x]+cost[y]<<"\n";
	}
	return 0;
}
