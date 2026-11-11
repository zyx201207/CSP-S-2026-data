#include <bits/stdc++.h>
using namespace std;
const int N=4005;
int C,T,n,k,f[N][N];
vector<int> g[N];
int rt,dep[N],mx,sum[N],pp;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[rt])rt=u;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
void Max(int &x,int y){
	x=x>y?x:y;
}
void dfs2(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs2(v,u);
	}
	for(int j=0;j<=mx;j++)f[u][j]=sum[j]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		for(int j=0;j<=mx;j++)sum[j]+=f[v][j],Max(f[u][j+1],f[v][j]);
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		for(int j=0;j<=mx;j++)Max(f[u][j+1],f[v][j]+(mx-j-2>=0?sum[mx-j-2]-f[v][mx-j-2]:0)+1);
	}
	f[u][0]=1;
	for(int j=0;j<=mx;j++)Max(pp,f[u][j]);
}
int getans(){
	int l=0,r=min(n,k);//
	while(l<=r){
		int mid=(l+r)/2;
		mx=mid;
		pp=0;
		dfs2(rt,0);
		if(pp>=k){
			r=mid-1;
		}else{
			l=mid+1;
		}
//		cout<<mid<<" "<<pp<<" ??\n";
	}
	return r+1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=2;i<=n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=1e9;
		rt=1;
		dep[rt]=0;
		dfs(rt,0);
		ans=min(ans,getans());
		dep[rt]=0;
		dfs(rt,0);
		ans=min(ans,getans());
		cout<<ans<<"\n";
	}
}
/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8


*/
