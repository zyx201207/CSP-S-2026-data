#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxm=5e5+10;
int c,n,m,d,Q;
int w[maxm];
struct egde{
	int nxt,w,to;
}e[maxm<<1];
int head[maxm],len;
void add(int u,int v,int w){
	e[++len].to=v;
	e[len].w=w;
	e[len].nxt=head[u];
	head[u]=len;
}
int more;
int dis[maxm];
bool vis[maxm];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijkstra(int s,int t){
	for(int i=1;i<=maxm;++i){
		dis[i]=LONG_LONG_MAX;
		vis[i]=0;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int pos=q.top().second;
		q.pop();
		if(vis[pos]){
			continue;
		}
		vis[pos]=1;
		for(int i=head[pos];i;i=e[i].nxt){
			if(dis[e[i].to]>dis[pos]+e[i].w){
				dis[e[i].to]=dis[pos]+e[i].w;
				q.push({dis[e[i].to],e[i].to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&Q);
	for(int i=1;i<=n;++i){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=m;++i){
		int sum;
		more++;
		scanf("%lld",&sum);
		for(int j=1;j<=sum;++j){
			int a,t;
			scanf("%lld%lld",&a,&t);
			add(n+more,a,t);
			add(a,n+more,t); 
		}
	}
	for(int i=1;i<=Q;++i){
		int s,t;
		scanf("%lld%lld",&s,&t);
		dijkstra(s,t);
		printf("%lld\n",dis[t]+w[s]+w[t]);
	}
	return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
