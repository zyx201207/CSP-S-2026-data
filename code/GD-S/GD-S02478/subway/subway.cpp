#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXM=500000,MAXN=500;
const ll inf=0x3f3f3f3f3f3f3f;
ll c,n,m,d,Q;
vector<pair<ll,ll> > ps[MAXM+5];
vector<pair<ll,ll> > E[MAXN+5];
ll w[MAXM+5],dis[MAXN+5][MAXN+5];
void Dij(ll h){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> > ,greater<pair<ll,ll> > > q;
	for(int i=1;i<=n;i++){
		if(i!=h&&dis[h][i]!=inf) q.push(make_pair(dis[h][i],i));
	}
	while(!q.empty()){
		ll nw=q.top().second;
		ll tw=q.top().first;
		q.pop();
		if(tw!=dis[h][nw]) continue;
		for(auto x:E[nw]){
			if(dis[h][x.first]>tw+x.second){
				dis[h][x.first]=tw+x.second;
				q.push(make_pair(dis[h][x.first],x.first));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("D:\\csps-new\\down\\subway\\subway1.in","r",stdin);
//	freopen("D:\\csps-new\\down\\subway\\subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;cin>>a>>t;
			ps[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++){
		for(int j=0;j<ps[i].size();j++){
			for(int k=j+1;k<ps[i].size();k++){
				dis[ps[i][j].first][ps[i][k].first]=min(dis[ps[i][j].first][ps[i][k].first],ps[i][j].second+ps[i][k].second);
				dis[ps[i][k].first][ps[i][j].first]=min(dis[ps[i][k].first][ps[i][j].first],ps[i][j].second+ps[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(i!=j&&dis[i][j]!=inf){
			E[i].push_back(make_pair(j,dis[i][j]));
		}
	}
	for(int i=1;i<=n;i++) Dij(i);
	for(int i=1;i<=Q;i++){
		ll st,ed;cin>>st>>ed;
		ll ans=inf;
		for(auto x:ps[st]) for(auto y:ps[ed]){
			ans=min(ans,w[st]+x.second+w[ed]+y.second+dis[x.first][y.first]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
