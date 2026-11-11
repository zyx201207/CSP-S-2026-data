#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;
const ll inf=1e12;
ll cas,t,n,k,ans=inf;
ll f[N][21],deep[N];
bool vis[N];
ll dis[N][N];
ll head[N],cnt=0;
struct node{
	ll v,nex;
}e[N*2];
void add(ll u,ll v){
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs1(ll u,ll fa){
	f[u][0]=fa;
	deep[u]=deep[fa]+1;
	for(int i=head[u];i;i=e[i].nex){
		ll v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
	}
}
ll LCA(ll x,ll y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[f[x][i]]>=deep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
ll calc(ll x,ll y){
	return deep[x]+deep[y]-2*deep[LCA(x,y)];
}
void dfs2(ll x,ll num){
	if(num>k) return;
	if(x==n+1){
		if(num<k) return;
		ll tmp=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!vis[f[i][0]]) tmp++;
		}
		if(tmp>2) return;
		ll record=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			for(int j=1;j<=n;j++){
				if(!vis[j]) continue;
				record=max(record,dis[i][j]);
			}
		}
		ans=min(ans,record);
		return;
	}
	if(num+1<=k){
		vis[x]=1;
		dfs2(x+1,num+1);
	}
	vis[x]=0;
	dfs2(x+1,num);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cas>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			ll u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs1(1,0);
		for(int j=1;j<=20;j++){
			for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=calc(i,j);
		}
		dfs2(1,0);
		cout<<ans<<"\n";
		cnt=0;
		ans=inf;
		for(int i=1;i<=n;i++){
			head[i]=0;
			deep[i]=0;
			vis[i]=0;
			for(int j=1;j<=n;j++) dis[i][j]=0;
		}
	}
	return 0;
} 
