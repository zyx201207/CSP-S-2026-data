#include<bits/stdc++.h>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll c,n,m,d,q,jj,jjj,x,y;

ll k,w[500007];
struct eg{
	ll d,v;
};
vector<eg>G[600008];//[1,n]route  [n+1,n+m]ting

struct node{
	ll w,v;
	bool operator < (const node &a)const{
		return w>a.w;
	}
};


ll dis[507][50007];
bool vis[500508];

void dij(ll s){
	memset(vis,0,sizeof(vis));
//	for(int i=1;i<=n+m;i++)dis[s][i]=0x7fffffff;
    memset(dis[s],0x3f,sizeof(dis[s]));
	dis[s][s]=0;
	priority_queue<node>q;
//	priority_queue<pair<ll,ll> >q;
//	q.push(mkp(0,s));
	q.push({0,s});
	while(!q.empty()){
		auto jj=q.top();q.pop();
//		ll u=jj.se;
		ll u=jj.v;
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:G[u]){
//			if(vis[i.v])continue;
			if(dis[s][i.v]>dis[s][u]+i.d){
				dis[s][i.v]=dis[s][u]+i.d;
	//			if(!vis[i.v])q.push(mkp(-1ll*dis[s][i.v],i.v));
				if(!vis[i.v])q.push({dis[s][i.v],i.v});
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>jjj>>jj;
			G[i].push_back({jj,jjj+n});
			G[jjj+n].push_back({jj,i});
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
//		for(int j=1;j<=n+m;j++)cout<<dis[i][j]<<" ";
	}
	while(q--){
		cin>>x>>y;
		ll ret=LLONG_MAX;
		for(int i=1;i<=n;i++){
			ret=min(dis[i][n+y]+dis[i][n+x],ret);
		}
		cout<<ret+w[x]+w[y]<<"\n";
	}
	return 0;
}


