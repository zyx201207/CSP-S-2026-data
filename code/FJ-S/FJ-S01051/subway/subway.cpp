#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2;
const int M=5e5;
const int Q=1e5;
const int inf=1e18; 
struct A{
	int v;
	int w;
};
struct Z{
	int to;
	int dis;
	bool operator<(const Z&other)const{
		return dis>other.dis;
	}
};
int c,n,m,d,q,flagA=1,flagB=1;
int k[505];
int ww[M+5];
int qs[Q+5];
int qe[Q+5];
vector<int> a[N+5];
vector<int> t[N+5];
vector<A> g[M+5];
vector<int> dis(M+5,inf);
vector<int> vis(M+5,0);
priority_queue<Z> pq;
void dijkstra(int s,int e){
	for(int i=1;i<=M+5;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().to;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//if(k[i]>2)flagA=0;
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=q;i++)cin>>qs[i]>>qe[i];
	/*int tt=t[1][0];
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			if(tt!=t[i][j])flagB=0;
		}
	}
	if(flagA){
		for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int d=0;d<k[i];d++){
				if(j==d)continue;
				g[a[i][j]].push_back({a[i][d],t[i][j]+t[i][d]});
				g[a[i][d]].push_back({a[i][j],t[i][j]+t[i][d]});
			}
		}
	}
	    for(int i=1;i<=q;i++){
	    	dijkstra(qs[i],qe[i]);
	    	cout<<dis[qe[i]]+ww[qs[i]]+ww[qe[i]]<<"\n";
		}   
		return 0;
	}
	if(flagB){
		for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int d=0;d<k[i];d++){
				if(j==d)continue;
				g[a[i][j]].push_back({a[i][d],2*tt});
				g[a[i][d]].push_back({a[i][j],2*tt});
			}
		}
		for(int i=1;i<=q;i++){
	    	dijkstra(qs[i],qe[i]);
	    	cout<<dis[qe[i]]+ww[qs[i]]+ww[qe[i]]<<"\n";
		}   
		return 0;
	}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int d=0;d<k[i];d++){
				if(j==d)continue;
				g[a[i][j]].push_back({a[i][d],t[i][j]+t[i][d]});
				g[a[i][d]].push_back({a[i][j],t[i][j]+t[i][d]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		dijkstra(qs[i],qe[i]);
		int papagei=dis[qe[i]]+ww[qs[i]]+ww[qe[i]];
		cout<<papagei<<"\n";
	}
	return 0;
}
