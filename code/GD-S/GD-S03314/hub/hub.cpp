#include<bits/stdc++.h>
using namespace std;
const int M=2e6;
int c,t,root=1,ans=0x3f3f3f3f;
int n,k,fa[M+7],dep[M+7];
vector<int> graph[M+7];
bool vis[M+7];
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void Dfs_search(int x,int fa,int dp){
	dep[x]=min(dep[x],dp);
	for(auto i:graph[x]){
		if(i==fa||vis[i]) continue;
		Dfs_search(i,x,dp+1);
	}
}
int sol(){
	int s=k,id=0,maxn=-1;
	for(int i=root;i<root+n;i++){
		fa[i]=i;
		dep[i]=0x3f3f3f3f;
	}
	for(int i=root;i<root+n;i++){
		if(vis[i]){
			for(int j:graph[i]){
				if(!vis[j]) continue;
				int u=find(i),v=find(j);
				if(u==v) continue;
				fa[u]=v;
				s-=1;
			}
		}
	}
	if(s>2) return 0x3f3f3f3f;
	for(int i=root;i<root+n;i++){
		if(vis[i]) Dfs_search(i,0,0);
	}
	for(int i=root;i<root+n;i++){
		maxn=max(maxn,dep[i]);
	}
//	for(int i=root;i<root+n;i++){
//		if(vis[i]) cout<<i<<" ";
//	}
//	cout<<maxn<<"\n";
	return maxn;
}
void Dfs(int id,int cnt){
	if(cnt>k) return ;
	if(n-id+1<k-cnt) return ;
	if(id==n+1){
		int s=sol();
		ans=min(s,ans);
		return ;
	}
	Dfs(id+1,cnt);
	vis[root+id-1]=1;
	Dfs(id+1,cnt+1);
	vis[root+id-1]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(n==k){
			cout<<0<<"\n";
		}
//		if(k>n/2) cout<<1<<"\n";
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			u+=root-1,v+=root-1;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ans=0x3f3f3f3f;
		if(n<=20) Dfs(1,0);
		else {
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					vis[i]=vis[j]=1;
					ans=min(sol(),ans);
					vis[i]=vis[j]=0;
				}
			}
		}
		cout<<ans<<"\n";
		root+=n;
	}
	return 0;
}
