#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q;
ll w[500005];
vector<pair<ll,ll> > e[505];
vector<pair<ll,ll> > p[500005];
map<pair<ll,ll>,ll> mp;
ll t;

int dijkstra(){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	int dis[250005];
	int vis[250005];
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[0]=0;
	pq.push({dis[0],0});
	while(!pq.empty()){
		int x=pq.top().second;
		pq.pop();
		if(vis[x]==1) continue;
		vis[x]=1;
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i].first,w=e[x][i].second;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				pq.push({dis[y],y});
			}
		}
	}
	return dis[t+1];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		vector<int> a;
		for(int j=1;j<=k;j++){
			ll u,v;
			cin>>u>>v;
			mp[{u,i}]=++t;
			a.push_back(t);
			p[u].push_back({v,i});
		}
		for(int j=1;j<a.size();j++){
			e[a[j-1]].push_back({a[j],0});
			e[a[j]].push_back({a[j-1],0});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<p[i].size();j++){
			ll np=p[i][j].second,nt=p[i][j].first,pp=p[i][j-1].second,pt=p[i][j-1].first;
			e[mp[{i,np}]].push_back({mp[{i,pp}],nt+pt});
			e[mp[{i,pp}]].push_back({mp[{i,np}],nt+pt});
		}
	}

	for(int i=1;i<=q;i++){
		ll ans;
		ll x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int j=0;j<p[x].size();j++){
			ll nn=mp[{x,p[x][j].second}],nt=p[x][j].first;
			e[0].push_back({nn,nt});
		}
		for(int j=0;j<p[y].size();j++){
			ll nn=mp[{y,p[y][j].second}],nt=p[y][j].first;
			e[nn].push_back({t+1,nt});
		}
		ans+=dijkstra();
		cout<<ans<<endl;
	}
	
	return 0;
}
