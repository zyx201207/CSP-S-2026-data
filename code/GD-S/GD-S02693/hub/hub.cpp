#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <cstring>
using namespace std;
#define ll long long
inline ll read(){
	ll f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
} 
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const ll N=1e6+10;
ll c,t,n,k,dep[N],ans;
vector<ll> g[N];
inline void glink(ll u,ll v){
	g[u].push_back(v),g[v].push_back(u);
}
inline void pre(){
	for(ll i=1;i<=n;i++) g[i].clear();
	ans=0;
}
inline void dfs(ll u,ll fa){
	dep[u]=dep[fa]+1;
	ans=max(ans,dep[u]);
	for(ll i=0;i<g[u].size();i++){
		ll v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
inline void solve(){
	n=read(),k=read();
	for(ll i=1;i<=n-1;i++){
		ll u=read(),v=read();
		glink(u,v);
	}
	dfs(1,0);
	write(ans/4),putchar('\n');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--) solve(),pre();
	return 0;
}
