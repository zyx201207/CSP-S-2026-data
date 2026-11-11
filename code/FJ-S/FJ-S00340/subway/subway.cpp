#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int v,w;//有权图 
};
int c,n,m,d,q;
int w[500005];
int dis[505][505];//任意两条线路的换乘代价
int k[505];
int a,t;
int x,y;
vector<edge>line[500005];//经过第i个点的线路集合
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int aa=1;aa<=k[i];aa++){
			cin>>a>>t;
			for(auto j:line[a]){//可到达的点内原有的车站 
				int v=j.v,w=j.w;
				dis[i][v]=min(dis[i][v],t+w);
				dis[v][i]=min(dis[v][i],t+w);
			}
			line[a].push_back({i,t});
		}
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
				dis[j][i]=min(dis[j][i],dis[i][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int mn=1e18;
		for(auto i:line[x]){
			for(auto j:line[y]){
				int u=i.v,v=j.v;
				mn=min(mn,dis[u][v]+i.w+j.w);
			}
		}
		cout<<mn+w[x]+w[y]<<"\n";
	}
	return 0;
}
