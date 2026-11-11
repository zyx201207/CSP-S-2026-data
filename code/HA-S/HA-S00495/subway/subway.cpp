#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=5e2+10;
int c,n,m,d,q;
int w[N],k;
long long a[N][M],t[N][M];
long long bfs(int x,int y){
	priority_queue <pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> qq;
	int dis[N];
	bool vis[N]={0};
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	qq.push({0,x});
	while(qq.size()){
		int u=qq.top().second;
		qq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:a[u]){
			if(dis[v]>dis[u]+t[u][v]){
				dis[v]=dis[u]+t[u][v];
				qq.push({dis[v],v});
			}
		}
	}
	return dis[y]+m;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<bfs(s,e)+w[s]+w[e]<<"\n";
	}
	return 0;
}

