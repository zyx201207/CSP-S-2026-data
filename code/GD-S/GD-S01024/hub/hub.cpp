#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=25;
int n,k,res,ans,dis[N];
vector<int>e[N];
bool vis[N];
void dfs(int mk,int u,int fa){
	vis[u]=1;
	for(auto v:e[u]){
		if(v==fa||!((1<<v-1)&mk)) continue;
		dfs(mk,v,u);
	}
}
void dfs2(int u,int fa,int mk){
	dis[u]=dis[fa]+1;
	for(auto v:e[u]){
		if(((1<<v-1)&mk)||v==fa) continue;
		dfs2(v,u,mk);
	}
}
void solve(){
	ans=2e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dis[0]=-1;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcountll(i)!=k) continue;
		int cnt=0;
		bool fl=1;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=1;j<=n;j++){
			if(!(i&(1<<j-1))) continue;
			if(!vis[j]){
				dfs(i,j,0);
				cnt++;
				if(cnt>2){
					fl=0;
					break;
				}
			}
		}
		if(!fl) continue;
		res=0;
		for(int j=1;j<=n;j++) dis[j]=0;
		for(int j=1;j<=n;j++){
			if(!((1<<j-1)&i)) continue;
			dfs2(j,0,i);
		}
		for(int j=1;j<=n;j++)res=max(res,dis[j]);
		if(res<ans){
//			cout<<i<<' ';
			ans=res;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
} 
/*
0 3 7 20 2
2 8 3 6 1 7 2 9
3 3 1 4 2 5 5 100
4 3 2 6 3 1 7 2
5 4 3 2 5 100 4 6 6 7
6 1 6
7 2 3
*/
