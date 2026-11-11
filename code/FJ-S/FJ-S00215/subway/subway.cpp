#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ft first
#define sc second
#define mkp(a,b) make_pair(a,b)

const ll inf=0x3f3f3f3f3f3f3f3f;
const int M=5e5+3,N=505;

int c,n,m,D,Q;
bool vis[M];
vector<vector<int> >e;
vector<vector<ll> >t;
map<int,vector<ll> >mp;
ll w[M];

vector<vector<ll> >d;
queue<int>q;
inline void dijkstra(int st){
	d.assign(m+1,vector<ll>(n+1,inf));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){d[st][i]=t[st][i];}
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto v:e[u]){
			bool isiq=true;
			if(vis[v]) continue;
			for(int i=1;i<=n;i++){
				if(t[u][i]!=inf && t[v][i]!=inf){
//					printf("cb with %d %d %d\n",u,v,i);
					for(int j=1;j<=n;j++){
						if(t[u][j]==inf) continue;
						if(d[u][j]+(t[u][j]+t[v][i])*(j!=i)<d[v][i]){
							d[v][i]=d[u][j]+(t[u][j]+t[u][i])*(j!=i);
//							printf("now,%d %d is %lld\n",v,i,d[v][i]);
//							printf("with d[%d][%d]=%lld %lld %lld\n",u,j,d[u][j],t[u][j],t[u][i]);
							if(isiq){
								q.push(v);
								isiq=false;
							}
						}
					}
				}
			}
		}
		if(u!=st)
			for(int i=1;i<=n;i++){
//				printf("%d %d-->%lld %lld\n",u,i,d[u][i],t[u][i]);
				d[u][i]+=t[u][i];
			}
				
	}
	for(int i=1;i<=m;i++){
		ll mn=inf;
		for(int j=1;j<=n;j++){
			mn=min(mn,d[i][j]);
//			printf("%lld ",d[i][j]>=inf?-1:d[i][j]);
		}
//		puts("");
		mp[st].push_back(mn);
	}
	return;
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
	e.resize(m+1);
	t.resize(m+1);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
		t[i].resize(n+1);
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		int lst=-1;
		for(int j=1;j<=k;j++){
			ll tmp;int sta;
			scanf("%d%lld",&sta,&tmp);
			t[sta][i]=tmp;
			if(lst!=-1){
				e[lst].push_back(sta);
				e[sta].push_back(lst);
			}
			lst=sta;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(t[i][j]==0)
				t[i][j]=inf;
		}
	}
	while(Q--){
		int st,ed;
		scanf("%d%d",&st,&ed);
		if(mp.find(st)!=mp.end()){
			printf("%lld\n",mp[st][ed-1]+w[ed]+w[st]);
			continue;
		}
		dijkstra(st);
		printf("%lld\n",mp[st][ed-1]+w[ed]+w[st]);
	}
	return 0;
}
