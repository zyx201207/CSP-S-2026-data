#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=5010;
const int INF=1e9;
int c,T;
int n,idx;
ll d;
ll p[N];
int head[N],dp[N],dis[N],I[N];
vector<int> g[N];

struct edge{
	int to,nxt;
}e[N*N];

void init(){
	idx=1;
	rep(i,1,n){
		head[i]=0;
	} 
}

void add_edge(int u,int v){
	++idx;
	e[idx].to=v;
	e[idx].nxt=head[u];
	head[u]=idx;
}

void init_bfs(){
	rep(i,1,n){
		dis[i]=INF;
		I[i]=0; 
		dp[i]=0;
	}
	rep(i,1,n)g[i].clear();
}

void bfs(int S){
	dis[S]=0;
	queue<int> q;
	q.push(S);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(dis[y]!=INF)continue;
			dis[y]=dis[x]+1;
			q.push(y); 
		}
	}
}

void add_graph(){
	for(int i=1;i<=n;++i){
		for(int k=head[i];k;k=e[k].nxt){
			int j=e[k].to;
			if(dis[j]==dis[i]+1){
				g[i].push_back(j);
//				printf("edge:%d->%d\n",i,j);
				I[j]++;
			}
		}
	}
}

void solve(ll &ans){
	
	//toposort
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(!I[i]){
			q.push(i);
			dp[i]=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:g[x]){
			--I[y];
			if(I[y]==0)q.push(y);
			dp[y]+=dp[x];
		}
	}
	rep(i,1,n){
		if(dp[i]==2){
			++ans;
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		scanf("%d %lld",&n,&d);
		rep(i,1,n){
			scanf("%lld",&p[i]);
		}
		init();
		for(int i=1;i<=n;++i){
			for(int j=i-1;j>=1;--j){
				if(abs(p[i]-p[j])<=d){
					add_edge(i,j);
//					printf("edge:%d->%d\n",i,j);
				}
			} 
			for(int j=i+1;j<=n;++j){
				if(abs(p[i]-p[j])<=d){
					add_edge(i,j);
//					printf("edge:%d->%d\n",i,j);
				}
			}
		}
		ll ans=0;
		for(int s=1;s<=n;++s){
			init_bfs();
			bfs(s);
			add_graph(); 
			solve(ans);
//			printf("\n");
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}

