#include<bits/stdc++.h>
using namespace std;
int rd(){
	int x=0;bool w=0;char c=getchar();
	while(c<'0'||c>'9')  c=='-'?w=1:0,c=getchar();
	while(c>='0'&&c<='9')  x=x*10+(c-48),c=getchar();
	return w?-x:x;
}
const int N=1005;
int n,k,fa[N],ans;
vector<int> g[N];
bool vis[N];
void init(int u,int fa){
	::fa[u]=fa;
	for(auto v:g[u])if(v!=fa)  init(v,u);
}
int find(int u,int fa){
	if(vis[u])  return 0;
	int res=1e9;
	for(auto v:g[u])if(v!=fa)  res=min(find(v,u),res);
	return res+1;
}
void dfs(int i,int j){
	if(j>k)  return;
	if(i==n+1){
		if(j!=k)  return;
		int cnt=0;
		for(int i=1;i<=n;i++)if(vis[i]&&!vis[fa[i]])  ++cnt;
		if(cnt>2)  return;
		int dis=0;
		for(int i=1;i<=n;i++)  dis=max(dis,find(i,0));
		ans=min(ans,dis);
		return;
	}
	vis[i]=1;dfs(i+1,j+1);
	vis[i]=0;dfs(i+1,j);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
for(int TC=rd(),T=rd();T--;){
	ans=n=rd(),k=rd();
	for(int i=1,u,v;i<n;i++){
		u=rd(),v=rd();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	init(1,0);
	dfs(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)  g[i].clear();
}
	return 0;
}
// 华风夏韵，洛水天依
