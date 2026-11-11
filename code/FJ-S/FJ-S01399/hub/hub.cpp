#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=3005;
const ll NN=1e5+5;
const ll inf=1e18;
ll n,k,fa[N],b[NN],c[NN],dis[N][N],D[NN];bool vis[N][N];vector<ll> G[NN];
struct edge{ll u,v;}e[NN];
void add(ll u,ll v){G[u].push_back(v),G[v].push_back(u);}
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void bfs(ll s){
	for(ll i=1;i<=n;i++) dis[s][i]=inf,vis[s][i]=0;
	queue<ll> q;q.push(s),dis[s][s]=0,vis[s][s]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		for(auto v:G[u]){
			if(vis[s][v]) continue;
			if(dis[s][v]>dis[s][u]+1) dis[s][v]=dis[s][u]+1,vis[s][v]=1,q.push(v);
		}
	}
}
void dfs(ll u,ll fa){
	D[u]=D[fa]+1;
	for(auto v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
	} 
}
void solve(){
	cin>>n>>k;ll ans=inf;
	if(n<=10){
		for(ll i=1;i<n;i++) cin>>e[i].u>>e[i].v,add(e[i].u,e[i].v);
		for(ll i=1;i<=n;i++) bfs(i);
		for(ll mask=0;mask<(1ll<<n);mask++){
			ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(mask&(1ll<<i-1)) cnt++;
			}
			if(cnt!=k) continue;
			bool flag=0;
			for(ll i=1;i<=n;i++) fa[i]=i;
			for(ll i=1;i<=n;i++){
				if((mask&(1ll<<e[i].u-1))&&(mask&(1ll<<e[i].v-1))){
					ll fx=find(e[i].u),fy=find(e[i].v);
					fa[fy]=fx;
				}
			}
			set<ll> st;
			for(ll i=1;i<=n;i++){
				if(mask&(1ll<<i-1)) st.insert(fa[i]);
			}
			if(st.size()>2) continue;
			ll mx=0;
			for(ll i=1;i<=n;i++){
				if(mask&(1ll<<i-1)) continue;
				else{
					ll d=inf;
					for(ll j=1;j<=n;j++){
						if(mask&(1ll<<j-1)) d=min(d,dis[i][j]);
					}
					mx=max(mx,d);
				}
			}ans=min(ans,mx);
		}
		cout<<ans<<endl;
	}else{
		map<pair<ll,ll>,bool> mp;
		for(ll i=1;i<n;i++) cin>>e[i].u>>e[i].v,add(e[i].u,e[i].v),mp[make_pair(e[i].u,e[i].v)]=mp[make_pair(e[i].v,e[i].u)]=1;
		cout<<(n==2?0:1)<<endl,mp.clear();
	}
	for(ll i=1;i<=n;i++) G[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	ll lzyakioi,T;cin>>lzyakioi>>T;
	while(T--) solve();
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

100+32+40+[15,30]=[187,202]
*/
