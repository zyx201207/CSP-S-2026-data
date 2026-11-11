#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+510,F=510,inf=1e18;
int disf[F][F],c,n,m,d,q;
int w[N];
int dis[N];
bool vis[N];
struct node{
	int id,w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};
vector <node> e[N];
inline void dijskra(int st){
	for(int i=1;i<=n+m;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	priority_queue <node> pq;
	pq.push({st,0});
	dis[st]=0;
	while(!pq.empty()){
		node u=pq.top();
		pq.pop();
		if(vis[u.id]) continue;
		vis[u.id]=1;
		for(auto &v:e[u.id]){
			if(dis[v.id]>u.w+v.w){
				dis[v.id]=u.w+v.w;
				pq.push({v.id,dis[v.id]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		disf[st][i]=dis[i];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) disf[i][j]=inf;
	}
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int aij,tij;
			scanf("%lld%lld",&aij,&tij);
			e[i].push_back({aij+n,tij});
			e[aij+n].push_back({i,tij});
		}
	}
	for(int i=1;i<=n;i++){
		dijskra(i);
	}
	while(q--){
		int xr,yr;
		scanf("%lld%lld",&xr,&yr);;
		int ans=w[xr]+w[yr],mn=inf;
		for(auto &x:e[xr+n]){
			for(auto &y:e[yr+n]){
				mn=min(mn,(x.w+y.w+disf[x.id][y.id]));
			}
		}
		ans+=mn;
		printf("%lld\n",ans);
	}
	return 0;
}
