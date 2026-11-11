#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,L=20;
int C,T,n,k,ans,dep[N],lg[N],f[N][L];
bool vis[N],mark[N];
vector<int> v[N];
void dfs1(int x,int fa){
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(auto to:v[x]){
		if(to==fa)continue;
		dfs1(to,x);
	}
}
void dfs(int x){
	mark[x]=true;
	for(auto to:v[x]){
		if(vis[to]&&!mark[to]){
			dfs(to);
		}
	}
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=L-1;~i;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline void check(){
	int cnt=0;
	fill(mark+1,mark+n+1,false);
	for(int i=1;i<=n;i++){
		if(!vis[i]||mark[i])continue;
		if(++cnt>2)return;
		dfs(i);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		int now=1e9;
		for(int j=1;j<=n;j++){
			if(!vis[j])continue;
			int lca=LCA(i,j);
			now=min(now,dep[i]-dep[lca]+dep[j]-dep[lca]);
		}
		res=max(res,now);
	}
	ans=min(ans,res);
}
void dfs2(int x,int cnt){
	if(cnt+(n-x+1)<k)return;
	if(cnt==k){
		check();
		return;
	}
	vis[x]=true;
	dfs2(x+1,cnt+1);
	vis[x]=false;
	dfs2(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,0);
		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
		for(int j=1;j<L;j++){
			for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
			}
		}
		ans=1e9;
		dfs2(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)v[i].clear();
	}
	return 0;
}
