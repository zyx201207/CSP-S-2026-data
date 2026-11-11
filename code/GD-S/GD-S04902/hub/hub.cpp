#include<bits/stdc++.h>
using namespace std;
int cid;
int n,k;
vector<int> e[110];
int vis[110],cnt;
void dfs(int u,int fa,int s){
	vis[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		if(!(s&(1<<(v-1)))) continue;
		dfs(v,u,s);
	}
}
int val[110];
void dfss(int u,int fa){
	for(auto v:e[u]){
		if(v==fa) continue;
		val[v]=min(val[v],val[u]+1);
		dfss(v,u);
	}
}
int ans,ppp;
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int S=1<<n;
	ppp=1e9;
	for(int s=0;s<S;s++){
		if(__builtin_popcount(s)!=k){
			continue;
		} 
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(int i=1;i<=n;i++){
			if(!(s&(1<<(i-1)))) continue;
			if(vis[i]) continue;
			dfs(i,0,s);
			cnt++;
		}
		if(cnt>2) continue;
		memset(val,0x7f,sizeof(val));
		for(int i=1;i<=n;i++){
			if(s&(1<<(i-1))){
				val[i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			dfss(i,0);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,val[i]);
		}
		ppp=min(ppp,ans);
	}
	cout<<ppp<<endl;
} 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int _;
	cin>>cid>>_;
	while(_--)solve();
	return 0;
}
