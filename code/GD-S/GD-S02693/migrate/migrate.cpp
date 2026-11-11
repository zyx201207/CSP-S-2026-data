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
const ll N=2e6+10,inf=0x3f3f3f3f3f3f3f3f;
ll c,t,n,d,a[N],rans,vis[5010][5010];
inline ll aps(ll x){
	if(x>=0) return x;
	else return -x;
}
struct node{
	ll to,dist;
};
struct cmp{
	bool operator()(node a,node b){
		return a.dist>b.dist;
	}
};
vector<node> g[N];
inline void pre(){
	for(ll i=1;i<=n;i++) g[i].clear();
	rans=0;
}
inline void glink(ll u,ll v,ll w){
	g[u].push_back({v,w}),g[v].push_back({u,w});
}
inline void dij(ll x){
	priority_queue<node,vector<node>,cmp> q;
	vector<ll> ans(n+2,inf);
	vector<ll> cnt(n+2,0);
	ans[x]=0,q.push({x,0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.dist>ans[u.to]) continue;
		for(ll i=0;i<g[u.to].size();i++){
			ll v=g[u.to][i].to,w=g[u.to][i].dist;
			if(ans[v]>u.dist+w) ans[v]=u.dist+w,q.push({v,ans[v]}),cnt[v]=cnt[u.to];
			else if(ans[v]==u.dist+w) cnt[v]++;
		}
	}
	/*cout<<"dis"<<x<<":";
	for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl<<"cnt"<<x<<":";
	for(ll i=1;i<=n;i++) cout<<cnt[i]<<" ";
	cout<<endl;*/
	for(ll i=1;i<=n;i++) if(cnt[i]==1&&(!vis[x][i])&&(!vis[i][x])) vis[x][i]=vis[i][x]=1,rans++;
}
inline void solve(){
	n=read(),d=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	//cout<<"*"<<endl;
	for(ll i=1;i<=n;i++){
		for(ll j=i-1;j>=1;j--) if(aps(a[i]-a[j])<=d) glink(i,j,1);
		for(ll j=1;j<=n;j++) vis[i][j]=0;
	}
	for(ll i=1;i<=n;i++) dij(i);
	write(rans),putchar('\n');
	//cout<<"*"<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--) solve(),pre(); 
	return 0;
}//Oct31==Dec25?
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
