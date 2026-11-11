#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=500005;
int c,n,m,d,q,w[M];
struct node{
	int v,w;
}; 
vector<node>g[N];
struct ljq{
	int sf,pri; 
};
vector<ljq>ok[M]; 
int dis[N][N],ftr[N][N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
void dijkstra(int s){
	memset(dis[s],0x3f,sizeof(dis[s]));
	pq.push({0,s});
	dis[s][s]=0;
	while(pq.size()){
		pair<int,int>nw=pq.top();
		pq.pop();
		int u=nw.second,w=nw.first;
		if(dis[s][u]<w)continue;
		for(auto v: g[u]){
			if(dis[s][v.v]>w+v.w){
				dis[s][v.v]=w+v.w;
				pq.push({w+v.w,v.v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			ok[a].push_back({i,t});
		}
	}
	memset(ftr,0x3f,sizeof(ftr));
	for(int i=1;i<=m;i++){
		for(auto v:ok[i]){
			for(auto w:ok[i]){
				int now=v.pri+w.pri;
				if(ftr[v.sf][w.sf]>now){
					ftr[v.sf][w.sf]=ftr[w.sf][v.sf]=now;
				}
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ftr[i][j]!=0x3f3f3f3f3f3f3f3f)g[i].push_back({j,ftr[i][j]});
		} 
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y],res=0x3f3f3f3f3f3f3f3f;
		for(auto v: ok[x]){
			for(auto w: ok[y]){
				res=min(res,dis[v.sf][w.sf]+v.pri+w.pri);
			}
		}
		cout<<ans+res<<'\n'; 
	}
}
