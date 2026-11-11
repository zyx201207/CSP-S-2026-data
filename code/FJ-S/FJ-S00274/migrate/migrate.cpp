#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+12,INF=1e18+12;
struct edge{
	int to;
	ll dist;
	friend bool operator<(const edge&i1,const edge&i2){
		return i1.dist>i2.dist;
	} 
};
ll n,d;
vector<edge>e[N];
ll x[N];
ll dis[N],cnt[N];
bitset<N>vis;
ll mn;
void dfs(const int u,const int sum){
	if(sum<dis[u]){
		dis[u]=sum,cnt[u]=1;
	}
	else if(sum==dis[u]){
		++cnt[u];
	}
	for(int v=u+1;v<=n;++v){
		if(x[v]-x[u]<=d){
			dfs(v,sum+1); 
		}
		else break;
	}
} 
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;++i)cin>>x[i];
//	for(int i=1;i<=n;++i)e[i].clear();
//	for(int u=1;u<=n;++u){
//		for(int v=u+1;v<=n;++v){
//			const ll w=x[v]-x[u];
//			if(w<=d)e[u].push_back({v,w}); 
//		}
//	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		fill(dis+1,dis+n+1,INF),fill(cnt+1,cnt+n+1,0);
		dfs(i,0);
		for(int j=i+1;j<=n;++j){
		
			if(cnt[j]==2){
					//cout<<"f:"<<i<<' '<<j<<' '<<dis[j]<<'\n';
				++ans;
			}
		} 
	} 
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;cin>>c>>t;
	while(t--)solve(); 
	return 0;
}
