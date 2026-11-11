#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const ll N = 501,M = 5e5 + 5,Q = 1e5 + 5,lINF = 0x3f3f3f3f3f3f3f3fLL,iINF = 0x3f3f3f3f;
ll c,n,m,d,q;
ll w[M];
struct station{
	int id,wlktme;
};
struct query{
	int sp,ep;
};
vector<station> subways[N];
vector<query> querys;
int vis[M];
//----------------------------------------------------
struct node{
	int to,w,next; 
}g[2 * N];
int cnt,head[N];
void addside(int x,int y,int z){
	cnt++;
	g[cnt].to = y;
	g[cnt].w = z;
	g[cnt].next = head[x];
	head[x] = cnt;
}
ll dis[N];
struct pqn{
	ll val,id;
	bool operator <(const pqn A)const{
		return A.val < val;
	}
};
void dijkstra(int v0){
	priority_queue<pqn> pq;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[v0] = 0;
	pq.push({dis[v0],v0});
	while(!pq.empty()){
		pqn f = pq.top();
		pq.pop();
		int u = f.id;
		if(vis[u])continue;
		vis[u] = 1;
		for(int j = head[u];j;j = g[j].next){
			int v = g[j].to;
			if(dis[u]+g[j].w < dis[v]){
				dis[v] = dis[u]+g[j].w; 
				pq.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	if(c >= 7 && c <= 11){
		struct station{
			int id,wlktme;
		};
		vector<station> subways[N];
		for(int i = 1;i<=n;i++){
			ll k;
			cin>>k;
			for(int j = 1;j<=k;j++){
				int nid,nwlktme;
				scanf("%lld %lld",&nid,&nwlktme);
				subways[i].push_back({nid,nwlktme});
			}
		}
		for(int i = 1;i<=n;i++){
			addside(subways[i][0].id,subways[i][1].id,subways[i][0].wlktme + subways[i][1].wlktme);
			addside(subways[i][1].id,subways[i][0].id,subways[i][0].wlktme + subways[i][1].wlktme);
		}
		for(int i = 1;i<=q;i++){
			int nsp,nep;
			scanf("%lld %lld",&nsp,&nep);
			dijkstra(nsp);
			printf("%lld\n",dis[nep]+w[nsp]+w[nep]);
		}
	}
	if(c == 20 || c == 21){
		int ans = INT_MAX;
		ll k1,k2;
		cin>>k1;
		map<int,int> otw1;
		for(int i = 0;i<=k1;i++){
			int otw,tml;
			cin>>otw>>tml;
			otw1[otw] = tml;
		}
		cin>>k2;
		for(int i = 1;i<=k2;i++){
			int otw,tml;
			cin>>otw>>tml;
			if(otw1[otw] != 0)ans = min(ans,otw1[otw] + tml);
		}
		for(int i = 1;i<=q;i++){
			int nsp,nep;
			scanf("%lld %lld",&nsp,&nep);
			dijkstra(nsp);
			printf("%lld\n",ans+w[nsp]+w[nep]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
