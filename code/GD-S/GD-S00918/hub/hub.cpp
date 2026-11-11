#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
const int N=1010;
vector<int>g[N];
bool vis[N],vis2[N];
int minn=1e9,maxn=-1,ans=1e9;
void dfs2(int x,int la){
	vis2[x]=1;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(u!=la&&vis[u]){
			dfs2(u,x);
		}
	}
}
void ckans(int x,int la,int dep){
	if(vis[x]) minn=min(minn,dep);
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(u!=la){
			ckans(u,x,dep+1);
		}
	} 
}
void ck(){
	int cnt=0;
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=n;i++){
		 if(vis[i]&&!vis2[i]) {
		 	dfs2(i,-1);
			 cnt++;	
		 }
	}	
	if(cnt>2) return;
	maxn=-1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			minn=1e9;
			ckans(i,-1,0);
			maxn=max(maxn,minn);
		}
	}
	ans=min(ans,maxn);
}
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=vis[i];
		}
		if(cnt==k)ck();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans=1e9;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
