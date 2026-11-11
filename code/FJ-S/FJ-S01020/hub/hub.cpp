#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define N 1000005
#define int long long
using namespace std;
int id,T,n,k;
vector<int> e[N];
int a[N],t[N],ans,dep[N];
bool vis[N],vis2[N];
void dfs2(int u,int fa){
	vis2[u]=true;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa)
			continue;
		if(t[v]&&!vis2[v])
			dfs2(v,u);
	}
}
void dfs3(int u,int fa){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa||vis2[v])
			continue;
		dep[v]=min(dep[v],dep[u]+1);
		dfs3(v,u);
	}
}
int check(){
	for(int i=1;i<=n;i++)
		vis2[i]=t[i]=0,dep[i]=n+5;
	for(int i=1;i<=k;i++)
		t[a[i]]=1,dep[a[i]]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(t[i]&&!vis2[i]){
			dfs2(i,0);
			cnt++;
		}
	}
	if(cnt>2)
		return n+5;
	for(int i=1;i<=n;i++)
		if(t[i])
			dfs3(i,0);
	int res=0;
	for(int i=1;i<=n;i++)
		res=max(res,dep[i]);
	return res;
}
void dfs(int x){
	if(x>k){
		ans=min(ans,check());
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>id>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear();
		ans=n+5;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
