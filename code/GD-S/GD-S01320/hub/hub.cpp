#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=310,inf=0x3f3f3f3f3f3f3f3f;
int tsk,T,n,k,u,v,vis[N],ans=inf,d[N][N],t[N][N],c[N][N],p[N];
vector<int> g[N];
void dfs2(int x){
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(!t[i][x])continue;
		vis[i]=1,dfs2(i);
	}
}
bool ch(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[i]&&p[j])t[i][j]=c[i][j];
		}
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	int yy=0;
	for(int i=1;i<=n;i++)if(!vis[i])dfs2(i),yy++;
	return (yy<=2);
}
void dfs(int step,int s){
	if(step==n+1){
		if(s<k)return;
		if(ch()){
			int res=0;
			for(int i=1;i<=n;i++){
				int mi=inf;
				for(int j=1;j<=n;j++)if(p[j]==1)mi=min(mi,d[i][j]);
				res=max(res,mi);
			}
			ans=min(ans,res);
		}
	}
	if(s<k)p[step]=1,dfs(step+1,s+1);
	p[step]=0,dfs(step+1,s);
}
void dfs3(int x,int fa,int s){
	d[s][x]=d[s][fa]+1;
	for(int y:g[x]){
		if(fa==y)continue;
		dfs3(y,x,s);
	}
}
void init(){
	for(int i=1;i<=n;i++)dfs3(i,0,i);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>tsk>>T;
	while(T--){
		cin>>n>>k,init(),ans=inf;
		for(int i=1;i<n;i++)cin>>u>>v,c[u][v]=1,g[u].push_back(v),g[v].push_back(u);
		dfs(1,0),cout<<ans<<'\n';
	}
}
