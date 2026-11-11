#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int c,n,m,d,p;
int w[N+5];
int dis[505][505],vis[505];
struct Road{
	int v;
	int w;
	bool operator < (const Road & other) const {
		return w>other.w;
	}
};
struct Bri{
	int a;
	int t;
	bool operator < (const Bri & other) const {
		return a<other.a;
	}
}bri[N+5];
vector<Road> road[N+5];
void dijkstra(int x){
	priority_queue<Road> pq;
	pq.push({x,0});
	while(!pq.empty()){
		Road r=pq.top();
		pq.pop();
		int to=r.v;
		int val=r.w;
		if(vis[to]) continue;
		vis[to]=1;
		for(auto p1:road[to]){
			int to_=p1.v;
			int val_=p1.w;
			if(dis[x][to_]>val+val_){
				dis[x][to_]=val+val_;
				pq.push({to_,dis[x][to_]});
			}
		}
	}
	return ;
}
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=LLONG_MAX;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>bri[j].a>>bri[j].t;
		sort(bri+1,bri+1+k);
		//for(int j=1;j<=k;j++) road[i].push_back({bri[j].a,bri[1].t+bri[j].t});
		for(int j=1;j<=k;j++) dis[bri[1].a][bri[j].a]=bri[1].t+bri[j].t;
	}
	/*for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++) if(i!=x) dis[x][i]=LLONG_MAX;
		dis[x][x]=0;
		dijkstra(x);
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}*/
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=i;k<=j;k++)
				if(dis[i][j]>dis[i][k]+dis[k][j]&&dis[k][j]!=LLONG_MAX&&dis[i][j]!=LLONG_MAX&&dis[i][k]!=LLONG_MAX)
					dis[i][j]=dis[i][k]+dis[k][j];
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
