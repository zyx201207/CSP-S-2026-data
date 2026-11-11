#include<iostream>
#include<vector>
#define int long long
using namespace std;
int c,t,n,k,f[1000005],vis[1000005],mn,ans;
vector<int> e[1000005];
void dfs2(int id){
	for(int i=0;i<e[id].size();i++){
		if(vis[e[id][i]]==1||f[e[id][i]]==0) continue;
		vis[e[id][i]]=1;
		dfs2(e[id][i]);
	}
}
void dfs3(int id,int fa,int d){
	if(f[id]==1){
		if(d<mn) mn=d;
		return;
	}
	for(int i=0;i<e[id].size();i++){
		if(e[id][i]==fa) continue;
		dfs3(e[id][i],id,d+1);
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		if(f[i]==1&&vis[i]==0){
			cnt++;
			dfs2(i);
		}
	}
	if(cnt>2) return 0;
	return 1;
}
void dfs1(int id,int ct){
	if(ct>k) return;
	if(id==n+1){
		if(ct!=k) return;
		if(!check()) return;
		int mx=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1) continue;
			mn=1e18;
			dfs3(i,0,0);
			if(mn>mx) mx=mn;
		}
		if(mx<ans) ans=mx;
		return;
	}
	f[id]=0;
	dfs1(id+1,ct);
	f[id]=1;
	dfs1(id+1,ct+1);
}
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans=1e18;
	dfs1(1,0);
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}
