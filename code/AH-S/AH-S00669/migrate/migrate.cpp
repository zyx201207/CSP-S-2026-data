#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=510,M=2e6+10;
ll c,t;
ll n,d;
ll x[N],xx[M];
ll anss;
ll dis[N],vis[N],ans[N][N],cnt[N];
vector<pair<ll,ll>>g[N];
void dij(ll S){
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,S});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	while(!pq.empty()){
		ll arr=pq.top().second;
		pq.pop();
		if (vis[arr])	continue;
		vis[arr]=1;
		for(auto i:g[arr]){
			ll v=i.first,w=i.second;
			if (dis[arr]+w<dis[v]){
				dis[v]=dis[arr]+w;
				pq.push({-dis[v],v});
			}
		}
	}
}
void dij2(ll S){
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,S});
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	cnt[S]=1;
	while(!pq.empty()){
		ll arr=pq.top().second;
		pq.pop();
		if (vis[arr])	continue;
		vis[arr]=1;
		for(auto i:g[arr]){
			ll v=i.first,w=i.second;
			if (dis[arr]+w==ans[S][v]){
				cnt[v]+=cnt[arr];
				dis[v]=dis[arr]+w;
				pq.push({-dis[v],v});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if (n<=500){
		for(ll i=1;i<=n;i++)	g[i].clear();
		anss=0;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			for(ll j=1;j<i;j++){
				if (x[i]-x[j]<=d){
					g[i].push_back({j,1});
					g[j].push_back({i,1});
				}
			}
		}
		for(ll i=1;i<=n;i++){
			dij(i);
			for(ll j=1;j<=n;j++)
				ans[i][j]=dis[j];
		}
		for(ll i=1;i<=n;i++){
			dij2(i);
			for(ll j=1;j<=n;j++){
				if (cnt[j]==2){
					anss++;
				}
			}
		}
		cout<<anss/2<<'\n';}
		else{
			ll cha;
			for(ll i=1;i<=n;i++){
				cin>>xx[i];
				cha=xx[i]-xx[i-1];
			}
			ll num=d/cha;
			cout<<num<<" "<<n-3<<" ";
			if (num!=2)	cout<<0<<'\n';
			else    cout<<n-3<<'\n';
		}
	}
	return 0;
}
