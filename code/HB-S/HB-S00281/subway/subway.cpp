#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define maxm ((int)(5e5)+10)
#define maxn (510)
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int c,n,m,d,q;
int fr(){
	int x=0,f=1;char ch=gc();
	while(!isdigit(ch)) ch=gc();
	while(isdigit(ch)){x=x*10+ch-'0';ch=gc();}
	return f*x;
}
vector <pair<int,int>> G[maxm+maxn];
int dis[maxn][maxm+maxn],w[maxm];
bool vis[maxm+maxn],has[maxn];
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void dijkstra(int st){
	memset(vis,0,sizeof(vis));
	for(int i=0; i<maxn+maxm; i++) dis[st][i]=INF;
	while(!pq.empty()) pq.pop();
	pq.push({0,st});
	dis[st][st]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;	
		for(auto &e:G[u]){
				int v=e.first,w=e.second;
				if(dis[st][v]>dis[st][u]+w){
					dis[st][v]=dis[st][u]+w;
					pq.push({dis[st][v],v});
				}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=fr(),n=fr(),m=fr(),d=fr(),q=fr();
	for(int i=1; i<=m; i++) w[i]=fr();
	for(int i=1; i<=n; i++){
		int k=fr();
		for(int j=1; j<=k; j++){
			int a=fr(),t=fr();
			G[i+m].pb({a,t});
			G[a].pb({i+m,t});
		}
	}
	while(q--){
		int x=fr(),y=fr();
		if(x>y) swap(x,y);
		if(!has[x]) dijkstra(x),has[x]=true;
		int ans=w[x]+w[y]+dis[x][y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
 I always look back to the past.
 The life turns to be stiil in my head in a moment. I turn  my memories to the clouds.
 The clouds are different:...
 */
