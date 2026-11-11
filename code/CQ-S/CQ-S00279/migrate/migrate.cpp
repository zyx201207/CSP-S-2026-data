#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 2000005
#define ll long long
ll c,t;
ll n,d;
ll a[N];
struct edge{
	ll v;
	ll w;
};
vector<edge>g[N];
ll dis[N],dis1[N],cnt[N];
bool vis[N],vis1[N];
priority_queue<edge>pq,pq1;
bool operator<(edge e1,edge e2){
	return e1.w>e2.w;
}
void dij(ll s){
	pq.push({s,0});
	dis[s]=0;
	while(pq.size()){
		ll u=pq.top().v;
		pq.pop();
		if(vis[u]) break;
		vis[u]=true;
		for(edge e:g[u]){
			if(dis[u]+e.w<dis[e.v]){
				dis[e.v]=dis[u]+e.w;
				pq.push({e.v,dis[e.v]});
			}
		}
	}
}
void dij1(ll s){
	pq1.push({s,0});
	dis1[s]=0;
	while(pq1.size()){
		ll u=pq1.top().v;
		pq1.pop();
		if(vis1[u]) break;
		vis1[u]=true;
		for(edge e:g[u]){
			if(dis1[u]+e.w<dis1[e.v]){
				dis1[e.v]=dis1[u]+e.w;
				pq1.push({e.v,dis1[e.v]});
			}
			if(dis1[u]+e.w==dis[e.v]) cnt[e.v]++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			while(g[i].size()) g[i].pop_back();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d) break;
				g[i].push_back({j,1});
				g[j].push_back({i,1});
			}
		}
		for(int l=1;l<=n;l++)
		for(int r=l+1;r<=n;r++){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			while(pq.size()) pq.pop();
			dij(l);
			memset(dis1,0x3f,sizeof(dis1));
			memset(cnt,0,sizeof(cnt));
			memset(vis1,0,sizeof(vis1));
			while(pq1.size()) pq1.pop();
			dij1(l);
			if(cnt[r]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//freopen
//feropen
