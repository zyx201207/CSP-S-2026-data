#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=1e6+10;
int n,k;
ll m,a[maxn],s[maxn];
int c,t;
vector<int> e[maxn];
int d[maxn];
bool vis[maxn],on[maxn];
void dfs(int x){
	if(vis[x]) return;
	vis[x]=1;
	for(int y:e[x]) if(on[y]) dfs(y);
}
void getd(int x){
	if(vis[x]) return;
	vis[x]=1;
	for(int y:e[x]) if(!vis[y]) d[y]=min(d[y],d[x]+1),getd(y);
}
inline bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++)
		if(on[i]&&!vis[i]) dfs(i),cnt++;
	return cnt<=2;
}
inline int get(){
	int ret=0;
	for(int i=1;i<=n;i++) d[i]=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0;
		if(on[i]) d[i]=0,getd(i);
	}
	for(int i=1;i<=n;i++) ret=max(ret,d[i]);
	return ret;
}
inline void sol1(){
	int ans=n;
	for(int i=0;i<1<<n;i++){
		if(__builtin_popcount(i)^k) continue;
		for(int j=1;j<=n;j++) on[j]=(i>>(j-1))&1;
		if(check()) ans=min(ans,get());
	}
	cout<<ans<<endl;
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	sol1();
	for(int i=1;i<=n;i++) e[i].clear();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);//
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
