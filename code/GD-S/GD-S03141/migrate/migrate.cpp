#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000005],n,d,c,T;/*,ans[5005][5005],inq[5005][5005],vis[2000005]
vector<ll> edge[2000005];
struct node{
	ll u,w,sum;
	friend bool operator<(const node& a,const node& b)const{
		return a.w>b.w;
	}
};
void dijkstra(int root){
	for(int i=1;i<=n;i++){inq[i]=0;vis[i]=0;ans[root][i]=INT_MAX;}
	priority_queue<node> q;
	q.push({root,0,1});
	ans[root][root]=0;
	inq[root]++;
	while(q.size()){
		int u=q.top().u,w=q.top().w,s=q.top().sum;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(ans[root][u]!=INT_MAX)
			for(int i=0;i<edge[u].size();i++)
				if(ans[edge[u][i]]>ans[u]+w){
					ans[edge[u][i]]=ans[u]+w;
					if(!inq[edge[u][i]][ans[u]+w]) q.push({edge[u][i],ans[u]+w,1});
					else q.push({edge[u][i],ans[u]+w,2});
				}
	}
	
}
bool is(ll a,ll b){
	for(int i=1;i<=n;i++) ans+=dijkstra(i);
}
void solve(){
	ll ans=0;scanf(" %lld%lld",&n,&d);for(int i=1;i<=n;i++) scanf(" %lld",x+i);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		if(x[j]-x[i]>d) break;
		else{
			edge[i].push_back(j);
			edge[j].push_back(i);
		}
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)if(is(i,j)) ans++;
	printf("%lld\n",ans);
}
*/
void solve(){
	ll ans=0;
	scanf(" %lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf(" %lld",x+i);
		ans^=x[i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) solve();
	return 0;
}
