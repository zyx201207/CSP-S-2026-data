#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int xsx=1e18;
constexpr int N=1e5+7,M=5e2+7;
int c,n,m,d,q,cnt[N];
vector<pair<int,int>> g[N];
map<pair<int,int>,int> mp;
int ksdfef=0;
int get(int x,int idx){
	if(!mp.count({x,idx})) mp[{x,idx}]=++ksdfef;
	return mp[{x,idx}];
}
int dist[M][N];
bool st[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
void dijkstra(int x,int dist[]){
	memset(st,0,sizeof(st));
	while(!pq.empty()) pq.pop();
	pq.push({0,x});
	dist[x]=0;
	while(!pq.empty()){
		pii tp=pq.top();
		pq.pop();
		int x=tp.second,dis=tp.first;
		if(st[x]) continue;
		st[x]=1;
		for(auto &it:g[x]){
			int to=it.first,len=it.second;
			if(dist[to]>dis+len){
				dist[to]=dis+len;
				pq.push({dist[to],to});
			}
		}
	}
}
signed main(){
	//0:Õ¾Ìü£¬1£ºÕ¾¿Ú£¬...:Õ¾Ì¨ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	fill(cnt+1,cnt+1+n,1);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%lld",&x);
		g[get(i,0)].push_back({get(i,1),x});
		g[get(i,1)].push_back({get(i,0),x});
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		int lst=0;
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			g[get(x,++cnt[x])].push_back({get(x,0),y});
			g[get(x,0)].push_back({get(x,cnt[x]),y});
			if(lst){
				g[get(lst,cnt[lst])].push_back({get(x,cnt[x]),0});
				g[get(x,cnt[x])].push_back({get(lst,cnt[lst]),0});
			}
			lst=x;
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		dijkstra(get(i,1),dist[i]);
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",dist[x][get(y,1)]);
	}
	return 0;
}

