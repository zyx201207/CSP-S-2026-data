#include<bits/stdc++.h>
using namespace std;
int n,k,T,c,res,t[100005],f[100005],siz[100005],ans,maxn;
vector<int> e[100005];
bool vis[100005];
void init(int u,int fa){
	f[u]=fa;
	siz[u]=1;
	for(auto v:e[u]){
		if(v!=fa){
			init(v,u);
			siz[u]+=siz[v];
		}
	}
}
void dfs(int u,int fa){
	for(auto v:e[u]){
		if(v!=fa){
			dfs(v,u);
		}
	}
}
void bfs(int s1,int s2){
	priority_queue<pair<int,int> > q;
	int cnt=2;
	for(auto v:e[s1]){
		if(v==f[s1]){
			q.push({n-siz[s1],v});
		}
		else{
			q.push({siz[v],v});
		}
	}
	for(auto v:e[s2]){
		if(v==f[s2]){
			q.push({n-siz[s2],v});
		}
		else{
			q.push({siz[v],v});
		}
	}
	while(cnt<k){
		cnt++;
		int u=q.top().second,w;
		vis[u]=1;
		for(auto v:e[u]){
			if(!vis[v]){
				if(f[u]==v){
					w=n-siz[u];
				}
				else{
					w=siz[v];
				}
				q.push({w,v});
			}
		}
	}
}
void ccc(int u,int fa){
	if(vis[u]){
		t[u]=0;
	}
	else{
		t[u]=min(t[u],t[fa]+1);
	}
	maxn=max(maxn,t[u]);
	for(auto v:e[u]){
		if(v!=fa){
			ccc(v,u);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=1e9;
		int u,v;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		memset(siz,0,sizeof(siz));
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		init(1,0);
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(x!=y){
					maxn=0;
					memset(vis,0,sizeof(vis));
					memset(t,0x3f,sizeof(t));
					dfs(x,0);
					dfs(y,0);
					vis[x]=vis[y]=1;
					bfs(x,y);
					ccc(x,0);
					ccc(y,0);
					ans=min(ans,maxn);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
