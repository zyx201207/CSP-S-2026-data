#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
struct edge{
	ll ed,nxt;
}b[2*N];
ll cid,Q,n,K,nbs[N],tot,f[N][25],dep[N],S[N],ans;
bool vis[N],co[N];
void add(ll x,ll y){
	b[++tot].ed=y; b[tot].nxt=nbs[x]; nbs[x]=tot;
}
void Lca(ll k,ll fa){
	f[k][0]=fa; dep[k]=dep[fa]+1;
	for(ll i=1;i<=20;i++) f[k][i]=f[f[k][i-1]][i-1];
	for(ll x=nbs[k];x;x=b[x].nxt){
		ll u=b[x].ed;
		if(u==fa) continue;
		Lca(u,k);
	}
}
ll LCA(ll x,ll y){
	if(dep[x]<dep[y]) swap(x,y);
	for(ll i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(ll i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}	
	return f[x][0];
}
void Dfs(ll k){
	co[k]=1;
	for(ll x=nbs[k];x;x=b[x].nxt){
		ll u=b[x].ed;
		if(!vis[u]) continue;
		if(!co[u]) Dfs(u);
	}
}
void dfs(ll k,ll x){
	if(x==K){
		for(ll i=1;i<=n;i++) co[i]=0;
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(!vis[i]) continue;
			if(!co[i]){
				Dfs(i);
				cnt++;
			}
		}
		if(cnt>2) return;
		ll maxx=0;
		for(ll i=1;i<=n;i++){
			ll minn=1e18;
			for(ll j=1;j<=K;j++){
				ll tmp=S[j];
				ll x=LCA(tmp,i);
				minn=min(minn,dep[i]+dep[tmp]-2*dep[x]);
			}
			maxx=max(maxx,minn);
		}
		ans=min(ans,maxx);
		return;
	}
	if(k>n) return;
	vis[k]=1;
	S[x+1]=k;
	dfs(k+1,x+1);
	vis[k]=0;
	dfs(k+1,x);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cid>>Q;
	while(Q--){
		cin>>n>>K;
		tot=0; ans=1e18;
		for(ll i=1;i<=n;i++) nbs[i]=0;
		for(ll i=1,x,y;i<=n-1;i++){
			cin>>x>>y;
			add(x,y); add(y,x); 
		}
		Lca(1,0);
		if(n<=10){
			dfs(1,0);
		}
		else{
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					ll maxx=0;
					for(ll k=1;k<=n;k++){
						ll minn=1e18;
						minn=min(minn,dep[k]+dep[i]-2*dep[LCA(k,i)]);
						minn=min(minn,dep[k]+dep[j]-2*dep[LCA(k,j)]);
						maxx=max(maxx,minn);
					}
					ans=min(ans,maxx);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
