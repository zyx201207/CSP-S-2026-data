#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
vector<int> g[105];
bool vis[105];
int len[105];
void dfs(int x,int u){
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]&&(x&(1<<v))){
			dfs(x,v);
		}
	}
}
void dfs2(int u){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(len[v]>len[u]+1){
			len[v]=len[u]+1;
			dfs2(v);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++){
			int oo=0;
			for(int j=0;j<n;j++){
				if((i&(1<<j))){
					oo++;
				}
			}
			if(oo!=k)continue;
			int cnt=0;
			memset(vis,0,sizeof(vis));
			memset(len,0x3f,sizeof(len));
			for(int j=0;j<n;j++){
				if((i&(1<<j))&&!vis[j]){
					dfs(i,j);
					cnt++;
				}
			}
			if(cnt>2)continue;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					len[j]=0;
					dfs2(j);
				}
			}
			int kk=0;
			for(int j=0;j<n;j++){
				kk=max(kk,len[j]);
			}
			ans=min(ans,kk);
		}
		printf("%d\n",ans);
	}
	return 0;
}
