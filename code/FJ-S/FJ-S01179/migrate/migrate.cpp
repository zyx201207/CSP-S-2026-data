#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll N=2e6+5,INF=2e18;

ll subtask,t,n,d,a[N],head[N],cur,dis[N],cnt[N],ans,vis[N];
struct edge{ll to,next,val;}e[N<<1];

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void add(ll u,ll v,ll w){e[++cur]={v,head[u],w};head[u]=cur;}

void dijkstra(ll st){
	for(ll i=1;i<=n;++i)dis[i]=INF,vis[i]=cnt[i]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,st});dis[st]=0;cnt[st]=1;
	while(!q.empty()){
		ll u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(ll i=head[u];i;i=e[i].next){
			ll v=e[i].to;
			
			if(dis[u]+e[i].val<dis[v]){
				dis[v]=e[i].val+dis[u],cnt[v]=cnt[u];q.push({dis[v],v});
			}
			else if(dis[u]+e[i].val==dis[v])cnt[v]+=cnt[u];
		} 
	}
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	subtask=read(),t=read();while(t--){
//		printf("TTTTTTTTTTTTTTTTT  %d\n",t+1);
		
		n=read(),d=read(),ans=cur=0;for(ll i=1;i<=n;++i)a[i]=read(),head[i]=0;
		for(ll i=1;i<=n;++i)for(ll j=i+1;j<=n;++j){if(a[j]-a[i]<=d){
			add(i,j,1);
		}}
		for(ll i=1;i<=n;++i){
			dijkstra(i);
//			printf("i=%lld\n dis=",i);
//			for(int j=1;j<=n;++j)printf(" %lld ",dis[j]);printf("\n cnt=");
//		 	for(int j=1;j<=n;++j)printf(" %lld ",cnt[j]);printf("\n");
			
			for(ll j=i+1;j<=n;++j)if(cnt[j]==2){
				++ans;
//				printf("ans=====%d %d\n",i,j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


