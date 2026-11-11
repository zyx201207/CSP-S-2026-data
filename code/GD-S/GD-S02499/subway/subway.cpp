#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
const int N=500+7,M=5e5+7;
int c,n,m,d,q;
int w[M],st[N];
struct edge{
	int v,c;
};
vector<edge> g[M+M];
int a[M],t[M];
int dis[M];
bool vis[M];
void spfa(int st,int ed){
	deque<int> q;
	q.push_front(st);
	for(int i=1;i<=n+m;i++) dis[i]=inf;
	dis[st]=0,vis[st]=true;
	while(!q.empty()){
		int u=q.front();q.pop_front();vis[u]=0;
		for(auto i:g[u]){
			int v=i.v,c=i.c;
			if(dis[u]+c<dis[v]){
				dis[v]=dis[u]+c;
				if(!vis[v]){
					vis[v]=true;
					if(q.empty()) q.push_front(v);
					else{
						if(dis[v]<dis[q.front()]) q.push_front(v);
						else q.push_back(v); 
					}
				}
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;// 地铁线路  地铁站 每个地铁站最多 
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		while(k--){
			int u,v,c;
			scanf("%lld%lld",&v,&c);
			u=i+m;
			g[u].push_back({v,c});
			g[v].push_back({u,c});
		}
	}
	while(q--){
		int st,ed;
		scanf("%lld%lld",&st,&ed);
		spfa(st,ed);
//		for(int i=m;i<=n+m;i++) cout<<dis[i]<<" ";
//		cout<<endl;
		printf("%lld\n",dis[ed]+w[st]+w[ed]);
	}
	return 0;
} 
