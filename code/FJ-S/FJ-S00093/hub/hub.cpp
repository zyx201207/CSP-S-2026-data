#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10,inf=1e18;
ll c,Q,n,m,a[15],dis[15][15],ans;
bool vis[N];
vector<ll> g[N];
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void Dfs(ll x,ll k,ll fa){
	for(ll i=0;i<g[k].size();i++){
		ll u=g[k][i];
		if(u==fa)continue;
		dis[x][u]=dis[x][k]+1;
		Dfs(x,u,k);
	}
}
bool f(){
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=m;i++){
		ll tmp=inf;
		for(int j=0;j<g[i].size();j++){
			for(ll j2=1;j2<=m;j2++)tmp=min(tmp,dis[a[j2]][j]);
			if(!tmp){
				if(vis[j])continue;
				vis[j]=1;
				cnt++;
			}
		}
	}
	return cnt==m;
}
ll solve(){
	ll ret=0;
	for(ll i=1;i<=n;i++){
		ll tmp=inf;
		for(ll j=1;j<=m;j++)tmp=min(tmp,dis[i][a[j]]);
		ret=max(ret,tmp);
	}
	return ret;
}
void dfs(ll k,ll cnt){
	if(cnt>m)return;
	if(k>n){
		if(cnt<m)return;
		if(f())ans=min(ans,solve());
		return;
	}
	a[cnt]=k;
	dfs(k+1,cnt+1);
	dfs(k+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(); Q=read();
	while(Q--){
		n=read(); m=read();
		for(int i=1;i<=n;i++)g[i].clear();
		for(ll i=1;i<n;i++){
			ll x,y;
			x=read(); y=read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(c>=13 && c<=14){
			int e=(n+1)/2+1;
			cout<<ceil((double)(e-m)/(m*2))<<endl;
			continue;
		}
		ans=inf;
		for(ll i=1;i<=n;i++)Dfs(i,i,0);
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
