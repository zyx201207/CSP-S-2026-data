#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
#define int long long
int c,n,m,d,q,wl[500010];

void fun1(){
	vector<vector<pair<int,int>>> E;
	E.resize(m+n+1);
	for(int i=1;i<=m;i++) cin>>wl[i];
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		for(int j=0;j<l;j++){
			int v,w;cin>>v>>w;
			E[i+m].push_back({v,w});
			E[v].push_back({i+m,w});
		}
	}
	int dist[500600];
	bool vis[500600];
	while(q--){
		for(int i=1;i<=m+n;i++){dist[i]=INT_MAX;vis[i]=0;}
		int b,e;cin>>b>>e;
		dist[b]=0;vis[b]=1;
		for(pair<int,int> j:E[b])
			if(dist[j.first]>dist[b]+j.second)
				dist[j.first]=dist[b]+j.second;
		for(int i=1;i<m+n;i++){
			int minj=0,mind=INT_MAX;
			for(int j=1;j<=m+n;j++)
				if(!vis[j] && dist[j]<mind){
					mind=dist[j];minj=j;
				}
			vis[minj]=1;
			for(pair<int,int> j:E[minj])
				if(dist[j.first]>dist[minj]+j.second)
					dist[j.first]=dist[minj]+j.second;
		}
		cout<<dist[e]+wl[b]+wl[e]<<'\n';
	}
}

void fun2(){
	for(int i=1;i<=m;i++) scanf("%lld",&wl[i]);
	int dist[1010][1010];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dist[i][j]=INT_MAX;
	for(int i=1;i<=n;i++){
		int l,u,uw,v,vw;
		scanf("%lld%lld%lld%lld%lld",&l,&u,&uw,&v,&vw);
		dist[u][v]=uw+vw;
		dist[v][u]=uw+vw;
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		int b,e;scanf("%lld%lld",&b,&e);
		printf("%lld\n",dist[b][e]+wl[b]+wl[e]);
	}
}

void fun3(){
	int t;
	vector<vector<int>> E;
	E.resize(m+n+1);
	for(int i=1;i<=m;i++) cin>>wl[i];
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		for(int j=0;j<l;j++){
			int u;cin>>u>>t;
			E[u].push_back(i+m);
			E[i+m].push_back(u);
		}
	}
	bool vis[500600];
	int dist[500600];
	while(q--){
		int i,e;cin>>i>>e;
		for(int j=1;j<=m+n;j++) vis[j]=0;
		queue<int> q;
		q.push(i);vis[i]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int j:E[u])
				if(!vis[j]){
					q.push(j);vis[j]=1;
					dist[j]=dist[u]+1;
				}
		}
		cout<<dist[e]*t+wl[i]+wl[e]<<'\n';
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c<=8){fun1();return 0;}
	if(c<=11){fun2();return 0;}
	if(c<=15){fun3();return 0;}
	//if(c<=21){fun4();return 0;}
}
