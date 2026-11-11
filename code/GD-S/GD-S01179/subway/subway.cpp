#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#include<cstring>

using i64=long long;
constexpr i64 inf=0x3f3f3f3f3f3f3f3f;

constexpr int maxn=500+1;
constexpr int maxm=5e5+7;

int W[maxm];
struct Edge{int v,w;};
std::vector<Edge>E[maxn+maxm];

i64 tmp[maxn+maxm];
i64 dis[maxn][maxn];
struct pii{int v;i64 w;};
bool operator<(pii lhs,pii rhs){//rev
	return lhs.w>rhs.w;
}
void dij(int s,i64 dis[])
{
	std::priority_queue<pii>pq;
	pq.push({s,0});
	while(!pq.empty()){
		const pii tmp=pq.top();pq.pop();
		const int u=tmp.v;
		if(dis[u]<=tmp.w) continue;
		dis[u]=tmp.w;
		for(auto e:E[u]){
			pq.push({e.v,dis[u]+e.w}); 
		}
	}
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int C,N,M,D,Q;std::cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++) std::cin>>W[i];
	for(int i=1;i<=N;i++){
		int k;std::cin>>k;
		for(int j=0;j<k;j++){
			int a,t;std::cin>>a>>t;
			E[a].push_back({i+M,t});
			E[i+M].push_back({a,t});
		}
	}
	
	for(int i=1;i<=N;i++){
		memset(tmp,0x3f,(N+M+7)*sizeof(*tmp));
		dij(i+M,tmp);
		for(int j=1;j<=N;j++) dis[i][j]=tmp[M+j];
	}
	
	while(Q--){
		int x,y;std::cin>>x>>y;//x!=y
		i64 ans=inf;
		for(auto e1:E[x]){
			for(auto e2:E[y])
				ans=std::min(ans,e1.w+e2.w+dis[e1.v-M][e2.v-M]);
		}
		ans+=W[x]+W[y];
		printf("%lld\n",ans);
	}
	
	return 0;
}

/*

struct Edge{int v,w;};
std::vector<Edge>E[maxn+maxm];

i64 dis[maxn][maxm+maxn];
struct pii{int v;i64 w;};
bool operator<(pii lhs,pii rhs){//rev
	return lhs.w>rhs.w;
}
void dij(int s,i64 dis[])
{
	std::priority_queue<pii>pq;
	pq.push({s,0});
	while(!pq.empty()){
		const pii tmp=pq.top();pq.pop();
		const int u=tmp.v;
		if(dis[u]<=tmp.w) continue;
		dis[u]=tmp.w;
		for(auto e:E[u]){
			pq.push({e.v,dis[u]+e.w}); 
		}
	}
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int C,N,M,D,Q;std::cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++) std::cin>>W[i];
	for(int i=1;i<=N;i++){
		int k;std::cin>>k;
		for(int j=0;j<k;j++){
			int a,t;std::cin>>a>>t;
			E[a].push_back({i+M,t});
			E[i+M].push_back({a,t});
		}
	}
	
	for(int i=1;i<=N;i++){
		memset(dis[i],0x3f,(N+M+7)*sizeof(*dis[i]));
		dij(i+M,dis[i]);
	}
	
	while(Q--){
		int x,y;std::cin>>x>>y;//x!=y
		i64 ans=inf;
		for(int i=1;i<=N;i++)
			ans=std::min(ans,dis[i][x]+dis[i][y]);
		ans+=W[x]+W[y];
		printf("%lld\n",ans);
	}
	
	return 0;
}
*/
