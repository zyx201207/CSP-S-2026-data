#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,dis1[500002],num[500002],vis[500002],X[100002],Y[100002],id,cnt,sum[500002];
vector<pair<ll,ll> > sta[500502];
vector<ll> dis[500002];
priority_queue<pair<ll,ll> > pq;
void dij(ll x){
	cnt=n+m;
	for(ll i=0;i<=n+m;++i){
		dis[id].push_back(-0x3f3f3f3f);
		vis[i]=0;
	}
	while(!pq.empty()) pq.pop();
	dis[id][x]=0;
	vis[x]=1;
	pq.push({0,x});
	while(cnt){
		--cnt;
		ll u=pq.top().second;
		vis[u]=1;
//		cout<<u<<"\n";
		for(ll i=0;i<sta[u].size();++i){
//			cout<<u<<"\n";
			ll v=sta[u][i].first,w=sta[u][i].second;
			if(vis[v]) continue;
			dis[id][v]=max(dis[id][v],dis[id][u]-w);
			pq.push({dis[id][v],v});
		}
		pq.pop();
	}
//	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i){
		cin>>dis1[i];
	}
	for(ll i=1;i<=n;++i){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;++j){
			ll v,w;
			cin>>v>>w;
			sta[v].push_back({i+m,w});
			sta[i+m].push_back({v,w});
		}
	}
	 
	for(ll i=1;i<=q;++i){
		ll x,y;
		cin>>x>>y;
		X[i]=x,Y[i]=y;
		++sum[x],++sum[y];
	}
	
	for(ll i=1;i<=q;++i){
		ll x=X[i],y=Y[i];
		if(!num[x] && !num[y]){
			if(sum[y]>sum[x]) swap(x,y);
			num[x]=++id;
			dij(x);
			cout<<-dis[id][y]+dis1[x]+dis1[y]<<"\n";
		}
		else if(num[x]){
			cout<<-dis[num[x]][y]+dis1[x]+dis1[y]<<"\n";
		}
		else if(num[y]){
			cout<<-dis[num[y]][x]+dis1[x]+dis1[y]<<"\n";
		}
	}
	return 0;
} 
