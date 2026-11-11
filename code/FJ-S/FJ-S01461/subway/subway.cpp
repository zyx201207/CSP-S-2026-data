#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,M=2e5+5,inf=1e18;
ll a,b,c,n,m,sum,ans,T,js[M][25],tt[M][25],tot[M]
,vis[N+M],len[N+M][N],d,Q,w[M],k[N],t,x,y;
struct node{
	ll u,len;
	bool operator>(const node& a) const {return len>a.len;}
};
priority_queue<node,vector<node>,greater<node> > q;
struct node1{
	ll v,w;
};
vector<node1> ma[N+M];
void dij(ll x){
	for(ll i=1;i<=n+m;i++)vis[i]=0,len[i][x-m]=inf;
	q.push({x,0});
	len[x][x-m]=0;
	while(!q.empty()){
		ll u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:ma[u]){
			ll v=it.v,w=it.w;
			if(len[v][x-m]>len[u][x-m]+w){
				len[v][x-m]=len[u][x-m]+w;
				q.push({v,len[v][x-m]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a>>t;
			ma[m+i].push_back({a,t});
			ma[a].push_back({m+i,t});
			js[a][++tot[a]]=i;
			tt[a][tot[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		dij(i+m);
	}
	for(ll q=1;q<=Q;q++){
		cin>>x>>y;
		ans=inf;
		for(int i=1;i<=tot[x];i++){
			ans=min(ans,len[y][js[x][i]]+tt[x][i]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	
	return 0;
}