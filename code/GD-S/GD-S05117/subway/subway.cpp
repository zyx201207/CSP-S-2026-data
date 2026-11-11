#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
struct edge{
	int v,w;
};
const int INF=1e9+5;
vector<edge> g[500005];
int n,m,c,d,q,a[500005],p[500005],vis[500005],dis[500005];
void dij(int s){
	for(int i=1;i<=m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push(make_pair(0,s));
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].v;
			int w=g[x][i].w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push(make_pair(dis[y],y));
			}
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int v[k+5],w[k+5];
		for(int j=1;j<=k;j++){
			cin>>v[j]>>w[j];
		}
		for(int j=1;j<k;j++){
			g[v[j]].push_back({v[j+1],w[j]+a[j]+w[j+1]+a[j+1]});
		}
		cout<<endl;
		for(int j=k;j>1;j--){
			g[v[j]].push_back({v[j-1],w[j]+a[j]+w[j-1]+a[j-1]});
		}
		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dij(y);
		cout<<dis[x]<<"\n";
	}
	return 0;
}

