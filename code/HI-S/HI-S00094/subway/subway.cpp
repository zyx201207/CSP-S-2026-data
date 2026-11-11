#include<bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
const int N=5e6+10;
const ll INF=1e18;
int c,n,m,d,q;
bool vis[N];
ll a[N],cnt,dis[N],ans[N];
ll pfen[N][2];
vector<pll> mp[N];
struct node{
	int u,v,id;
}ask[N];
bool cmp(node a,node b){
	return a.u<b.u;
}
void dij(int s){
	priority_queue<pll,vector<pll>,greater<pll> > q;
	for(int j=1; j<=cnt; j++) vis[j]=0,dis[j]=INF;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		ll u=q.top().second;
		q.pop();
		vis[u]=1;
		for(int j=0; j<mp[u].size(); j++){		
			ll v=mp[u][j].first,w=mp[u][j].second;
			if(!vis[v] && dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}	
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	cnt=m;
	for(int j=1; j<=m; j++) cin>>a[j];
	for(int j=1; j<=n; j++){
		int K;
		cin>>K;
		cnt++;
		for(int k=1; k<=K; k++){
			ll v,w;
			cin>>v>>w;
			mp[v].push_back({cnt,w});
			mp[cnt].push_back({v,w});
			if(c==20 || c==21){
				if(!pfen[v][0]) pfen[v][0]=w;
				else pfen[v][1]=w;
			}
		}
	}
	for(int j=1; j<=q; j++){
		cin>>ask[j].u>>ask[j].v;
		ask[j].id=j;
		if(ask[j].u>ask[j].v) swap(ask[j].u,ask[j].v);
	}
	sort(ask+1,ask+q+1,cmp);
	int s=0;
	for(int j=1; j<=q; j++){
		if(c==20 || c==21){
			if(pfen[ask[j].u][0] && pfen[ask[j].v][0] && pfen[ask[j].u][1] && pfen[ask[j].v][1]){
				ll lans=pfen[ask[j].u][0]+pfen[ask[j].v][0];
				ll rans=pfen[ask[j].u][1]+pfen[ask[j].v][1];
				ans[ask[j].id]=a[ask[j].u]+a[ask[j].v]+min(lans,rans);
				continue;
			}else{
				if(pfen[ask[j].u][0] && pfen[ask[j].v][0]){
					ans[ask[j].id]=a[ask[j].u]+a[ask[j].v]+pfen[ask[j].u][0]+pfen[ask[j].v][0];
					continue;
				}else{
					if(pfen[ask[j].u][1] && pfen[ask[j].v][1]){
						ans[ask[j].id]=a[ask[j].u]+a[ask[j].v]+pfen[ask[j].u][1]+pfen[ask[j].v][1];
						continue;
					}
				}
			}	
		}
		if(ask[j].u!=s){
			dij(ask[j].u);
			s=ask[j].u;
		}
		ans[ask[j].id]=dis[ask[j].v]+a[ask[j].u]+a[ask[j].v];
	}
	for(int j=1; j<=q; j++) cout<<ans[j]<<"\n";
	return 0;
}
