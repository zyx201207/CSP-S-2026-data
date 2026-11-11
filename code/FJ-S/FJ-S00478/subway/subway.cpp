#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
	ll v,w,xian;
};

const int N=510,M=1e4*2+10;
using P=pair<long long,int>;
priority_queue<P,vector<P>,greater<P> > p,kong;
vector<node> g[M];
ll dist[M];
int huan[N][M];
int c,n,m,d,q;
int w[N];
int a[M],t[M];

void dijkstra(int start,int end){
	p.emplace(0,start);
	for(int i=1;i<=m;i++) dist[i]=LLONG_MAX;
	dist[start]=0;
	while(!p.empty()){
		P nw=p.top();
		p.pop();
		int d=nw.first;
		int u=nw.second;
		if(dist[u]!=d) continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			int xian=g[u][i].xian;
			if(dist[u]+w+huan[xian][u]<=dist[v]){
				dist[v]=dist[u]+w+huan[xian][u];
				p.emplace(dist[v],v);
			} 	
		}
	}
	cout<<dist[end]+w[start]+w[end]<<'\n';
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			huan[i][a[j]]=t[j];
		} 
		
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(a[j]!=a[l]){
					node ppp;
					ppp.v=a[l],ppp.w=t[l],ppp.xian=i;
					g[a[j]].push_back(ppp);
				}
			}
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
	} 
	return 0;
}

