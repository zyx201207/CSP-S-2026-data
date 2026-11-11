#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll tp,n,m,d,q,w[500005],k[505],s[500005],t[500005];
struct nd{
	ll v,w;
	bool operator <(const nd &x)const{
		return w<x.w;
	};
};
vector<nd>adj[500005],a[505];
ll vis[505][505],dis[505][505],lj[505][505];
void dij(ll rt){
	priority_queue<nd>q;
	q.push({rt,0});
	dis[rt][rt]=0;
	while(!q.empty()){
		nd u=q.top();q.pop();
		if(vis[rt][u.v])continue;
		vis[rt][u.v]=1;
		for(nd v:a[u.v]){
			if(dis[rt][v.v]>dis[rt][u.v]+v.w){
				dis[rt][v.v]=dis[rt][u.v]+v.w;
				q.push({v.v,dis[rt][v.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>tp>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s[j]>>t[j];
			adj[s[j]].push_back({i,t[j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=lj[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(nd u:adj[i]){
			for(nd v:adj[i]){
				if(u.v==v.v)continue;
				lj[u.v][v.v]=min(lj[u.v][v.v],u.w+v.w);
				lj[v.v][u.v]=lj[u.v][v.v];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(lj[i][j]!=inf){
				a[i].push_back({j,lj[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		ll x,y,ans=inf;
		cin>>x>>y;
		for(nd u:adj[x]){
			for(nd v:adj[y]){
				ans=min(ans,v.w+u.w+dis[u.v][v.v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
qui n<=500 ge di tie zhan de SP
*/
