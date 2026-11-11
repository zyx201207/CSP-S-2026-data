#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=1e18;
int n,m,d,q,len[N];
long long w[M];
vector<pair<int,long long>> g[M];//站内线路编号
//vector<pair<int,long long>> e[N];//一条线路视为一个点，构成的图 
long long dis[N][N];//甚至可以用floyd 
void init(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int l=g[i].size();
		for(int j=0;j<l;j++){
			for(int k=j+1;k<l;k++){
				int u=g[i][j].first,v=g[i][k].first;//线路编号 
				long long w=g[i][j].second+g[i][k].second;//进出两个站的时间 
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			long long u,w;
			cin>>u>>w;
			g[u].push_back({i,w});
		}
	}
	init();
	floyd();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<":";
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j].first<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
//	cout<<"?"<<endl;
		int x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y],minn=inf;//进出站点
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i].first,v=g[y][j].first;
				minn=min(minn,dis[u][v]+g[x][i].second+g[y][j].second);
//				cout<<u<<" "<<v<<":"<<dis[u][v]+g[x][i].second+g[y][i].second<<endl;
			} 
		}
		cout<<ans+minn<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1,TT;
//	cin>>T;
	cin>>TT;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
2 3

*/
