#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=20;
ll t,n,k,x,y,ans,sl,mi,cnt;
vector<int>v[N];
bool f[N],vis[N];
void dfs1(int x){
	vis[x]=1;
	for(auto u:v[x]){
		if(!vis[u] && f[u]) dfs1(u), vis[u]=1;
	}
}
void dis(int x, ll sum, int fa){
	if(f[x]){
		mi=min(mi,sum);
		return;
	}
	for(auto u:v[x]){
		if(u==fa) continue;
		dis(u,sum+1,x);
	}
}
void check(){ cnt=0, sl=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i] && f[i]){
			dfs1(i), ++sl;
		}
	}
	if(sl>2) return;
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		mi=(1e9), dis(i,0,-1), cnt=max(cnt,mi); 
	//	cout<<i<<' '<<mi<<endl;
	}ans=min(ans,cnt);
}
void dfs(int x, int sl1){
	if(sl1>k) return;
	if(x==n+1){
		if(sl1==k) check();
		return;
	}
	f[x]=1, dfs(x+1,sl1+1);
	f[x]=0, dfs(x+1,sl1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<n;i++){
		cin>>x>>y, v[x].pb(y), v[y].pb(x);
	}ans=(1e9);
	dfs(1,0), cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--) solve();
	return 0;
}
/*

*/
