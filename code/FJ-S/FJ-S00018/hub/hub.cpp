#include <iostream>
#include <vector>
#define N 2000005
using namespace std;
int c,t,n,k,u,v,s[N],ans,minn;
bool vis[N],vis2[N];
vector<int> V[N];
void dfs3(int u,int fa,int len){
	if(vis2[u]){
		minn=min(minn,len);
	}
	for(int v:V[u]){
		if(v==fa) continue;
		dfs3(v,u,len+1);
	}
}
void dfs2(int u,int fa){
	vis[u]=true;
	for(int v:V[u]){
		if(v==fa||!vis2[v]) continue;
		dfs2(v,u);
	}
}
void dfs(int x,int cnt){
	if(x>n||cnt==k){
		if(cnt!=k) return;
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
		int sum=0;
		for(int i=1;i<=cnt;i++){
			if(!vis[s[i]]){
				dfs2(s[i],0);
				++sum;
			}
		}
		if(sum<=2){
			int tmp=0;
			for(int i=1;i<=n;i++){
				minn=1e9;
				dfs3(i,0,0);
				tmp=max(tmp,minn);
			}
			ans=min(ans,tmp);
		}
		return;
	}
	s[cnt+1]=x;
	vis2[x]=true;
	dfs(x+1,cnt+1);
	vis2[x]=false;
	dfs(x+1,cnt);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			V[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		if(c<=3){
			ans=1e9;
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
