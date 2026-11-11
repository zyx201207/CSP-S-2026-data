#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<functional>

/*
Limit of Points:
for a station id i:
At platform : i.
At station : i + m.
At entrance : i + m + m.
*/

static inline void swap(int * f,int * s){
	if(*f==*s || f==s){
		return ;
	}
	*f^=*s;
	*s^=*f;
	*f^=*s; 
}

const long long int inf=(1ll<<62);

int c,n,m,d,q,station_cnt;

struct OI{
	int v;
	int floor;
	long long int w;
};
std::vector<OI> e[(int)2e4+5][505];
long long int dis[(int)2e4+5][505];
long long int map[1009][1009];
bool vis[(int)2e4+5][505];

struct Heap{
	long long int weight;
	int u;
	int floor;
};

static inline void Dijkstra(int begin){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n+2;j++){
			dis[i][j]=inf;
			vis[i][j]=false;
		}
	}
	dis[begin][0]=0;
	auto Compare=[](const Heap & f,const Heap & s){
		return f.weight>s.weight;
	};
	std::priority_queue<Heap,std::vector<Heap>,decltype(Compare)> q(Compare);
	q.push((Heap){0,begin,0});
	while(!q.empty()){
		int u=q.top().u;
		int floor=q.top().floor;
	//	printf("u %d, floor %d\n",u,floor);
		q.pop();
		if(vis[u][floor]==true){
			continue;
		}
		vis[u][floor]=true;
		for(const OI & eg:e[u][floor]){
			int v=eg.v,nfloor=eg.floor;
			long long int w=eg.w;
	//		printf("v %d, nfloor %d, w %lld\n",v,nfloor,w);
			if(vis[v][nfloor]==true){
				continue;
			}
			if(dis[v][nfloor]>dis[u][floor]+w){
				dis[v][nfloor]=dis[u][floor]+w;
				q.push({dis[v][nfloor],v,nfloor});
			}
		}
	}
	return ;
}

static inline void Online_solve(void){
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		Dijkstra(u);
		printf("%lld\n",dis[v][0]);
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		long long int w;
		scanf("%lld",&w);
		e[i][0].push_back({i,1,w});
		e[i][1].push_back({i,0,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int * path=(int * )calloc(k+1,sizeof(int));
		for(int j=1;j<=k;j++){
			int a;
			long long int t;
			scanf("%d%lld",&a,&t);
			e[a][2+i-1].push_back({a,1,t});
			e[a][1].push_back({a,2+i-1,t});
			path[j]=a;
			if(j==1){
				continue;
			}
			e[path[j-1]][2+i-1].push_back({a,2+i-1,0});
			e[a][2+i-1].push_back({path[j-1],2+i-1,0});
		}
		free(path);
	}
	if(m>q){
		Online_solve();
		return 0;
	}
	for(int i=1;i<=m;i++){
		Dijkstra(i);
		for(int j=1;j<=m;j++){
			int u=i,v=j;
			if(u<v){
				swap(&u,&v);
			}
			map[u][v]=dis[j][0];
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u<v){
			swap(&u,&v);
		}
		printf("%lld\n",map[u][v]);
	}
	return 0;
}
