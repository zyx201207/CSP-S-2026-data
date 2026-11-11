#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
struct edge{
	ll ed,nxt;
}b[2*N];
struct node{
	ll x,dis;
};
ll cid,Q,n,d,x[N],nbs[N],tot,dis[N],f[N],ans;
queue<node> q;
void add(ll x,ll y){
	b[++tot].ed=y; b[tot].nxt=nbs[x]; nbs[x]=tot;
}
void bfs(ll s){
	dis[s]=0; f[s]=1;
	q.push({s,0});
	while(!q.empty()){
		node tmp=q.front(); q.pop();
		if(tmp.dis>dis[tmp.x]) continue;
		for(ll x=nbs[tmp.x];x;x=b[x].nxt){
			ll u=b[x].ed;
			if(dis[tmp.x]+1<dis[u]){
				dis[u]=dis[tmp.x]+1;
				f[u]=f[tmp.x];
				q.push({u,dis[u]});
			}
			else if(dis[tmp.x]+1==dis[u]) f[u]+=f[tmp.x];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cid>>Q;
	while(Q--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		tot=0;
		for(ll i=1;i<=n;i++) nbs[i]=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					add(i,j);
					add(j,i);
				}
			}
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++) dis[j]=1e18,f[j]=0;
			bfs(i);
			for(ll j=i+1;j<=n;j++){
				if(f[j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
