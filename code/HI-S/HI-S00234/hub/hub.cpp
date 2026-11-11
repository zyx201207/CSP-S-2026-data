#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,k;
int vis[N];
vector<int>G[N];
void dfs(int u,int x){
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v])continue;
		if(!((1<<(v-1))&x))continue;
		dfs(v,x);
	}
}
int dfs1(int rt,int u,int fa,int mj){
	int mn=0x3f3f3f3f;
	for(auto v:G[u]){
		if(v==fa)continue;
		if((1<<(v-1))&mj){
			mn=min(mn,1);
		}else{
			mn=min(mn,dfs1(rt,v,u,mj)+1);
		}
	}
	return mn;
}
int bitnum(int x){
	int ret=0;
	while(x){
		if(x&1)ret++;
		x>>=1;
	}
	return ret;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=0x3f3f3f3f;
	for(int mj=0;mj<(1<<n);mj++){
		if(bitnum(mj)!=k){
			continue;
		}
		int tmp=0;
		memset(vis,0,sizeof(vis));
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&(1<<(i-1))&mj)dfs(i,mj),cnt++;
		}
		if(cnt>2)continue;
		for(int i=1;i<=n;i++){
			if((1<<(i-1))&mj)continue;
			tmp=max(tmp,dfs1(i,i,i,mj));
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans); 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
