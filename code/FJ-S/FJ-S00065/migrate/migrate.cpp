#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2000005;
ll c,t,n,d,x[N],dis[N],cnt[N],ans;
vector<ll> G[N];
bool vis[N];
void bfs(ll s){
	queue<ll> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		vis[s]=0;
		for(ll i=0;i<G[u].size();i++){
			ll v=G[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=1;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1){
				++cnt[v];
				q.push(v);
			} 
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(n<=10000){
			for(ll i=1;i<=n;i++){
				for(ll j=i;j<=n;j++){
					if(i==j) continue;
					if(x[j]-x[i]<=d){
						G[i].push_back(j);
					} 
				}
			}
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					vis[j]=cnt[j]=0;
					dis[j]=1e18;
				} 
				bfs(i);
				//cout<<dis[n]<<" ";
				for(ll j=i;j<=n;j++){
					if(cnt[j]==2){
						//printf("%lld %lld\n",i,j);
						++ans;
					} 
				} 
			}
			printf("%lld\n",ans);
			for(ll i=1;i<=n;i++) G[i].clear();
		}
	}
	return 0;
}
