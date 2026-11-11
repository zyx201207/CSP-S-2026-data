#include<bits/stdc++.h>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;
const int N=110;
int C,T,n,K,u[N],v[N],dep[N],fa[N],dis[N],val[N][N],mx,mxd[N],siz[N],dp[N][N],f[N];
vector<int> edge[N],vc,edge1[N],nd1,nd2;
inline void dfs0(int u){
	for(auto &i:edge[u])
		if(i!=fa[u]){
			fa[i]=u,dep[i]=dep[u]+1;
			dfs0(i);
		}
}
struct node{
	int cu,cv;
};
inline node get(int u,int v){
	vector<int> vc1,vc2;
	vc.clear();
	while(dep[u]>dep[v])
		vc1.push_back(u),u=fa[u];
	while(dep[v]>dep[u])
		vc2.push_back(v),v=fa[v];
	while(u!=v)
		vc1.push_back(u),vc2.push_back(v),u=fa[u],v=fa[v];
	vc1.push_back(u),reverse(vc2.begin(),vc2.end());
	for(auto &i:vc2)
		vc1.push_back(i);
	if(vc1.size()==2) return {0,0};
	else return {vc1[1],vc1[vc1.size()-2]};
}
inline void dfs1(int u,int f,int d,int op){
	if(!op) dis[u]=d;
	else dis[u]=min(dis[u],d),mx=max(mx,dis[u]);
	for(auto &i:edge1[u])
		if(i!=f) dfs1(i,u,d+1,op);
}
inline void link(int u,int v){
	edge1[u].push_back(v),edge1[v].push_back(u);
}
inline void dfs2(int u,int f,int op){
	mxd[u]=1;
	if(!op) nd1.push_back(u);
	else nd2.push_back(u);
	for(auto &i:edge[u])
		if(i!=f){
			dfs2(i,u,op);
			mxd[u]=max(mxd[u],mxd[i]+1);
		}
}
inline void chk(int &x,int y){
	x=min(x,y);
}
inline void dfs3(int u,int fa){
	for(auto &i:edge[u])
		if(i!=fa) dfs3(i,u);
	siz[u]=1,dp[u][1]=0;
	for(auto &i:edge[u])
		if(i!=fa){
			memset(f,63,sizeof(f));
			for(int j=1;j<=siz[u];j++)
				chk(f[j],max(dp[u][j],dp[i][0]));
			for(int j=1;j<=siz[u];j++)
				for(int k=1;k<=siz[i];k++)
					chk(f[j+k],max(dp[u][j],dp[i][k]));
			siz[u]+=siz[i];
			for(int i=1;i<=siz[u];i++)
				dp[u][i]=f[i];
		}
	dp[u][0]=mxd[u];
}
inline void Main(){
	mem(dep),mem(fa);
	cin>>n>>K;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		edge[u[i]].push_back(v[i]),edge[v[i]].push_back(u[i]); 
	}
	dep[1]=1;
	dfs0(1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			node r=get(i,j);
			if(!r.cu) val[i][j]=0;
			else{
				for(int k=1;k<=n;k++)
					edge1[k].clear();
				for(int k=1;k<n;k++)
					if(u[k]!=i&&v[k]!=i&&u[k]!=j&&v[k]!=j) link(u[k],v[k]);
				link(i,r.cu),link(j,r.cv),mx=0;
				dfs1(i,0,0,0),dfs1(j,0,0,1);
				val[i][j]=mx;
			}
		}
	int ans=n;
	for(int i=1;i<n;i++){
		mem(mxd),nd1.clear(),nd2.clear(),mem(siz);
		dfs2(u[i],v[i],0),dfs2(v[i],u[i],1);
		memset(dp,63,sizeof(dp));
		dfs3(u[i],v[i]),dfs3(v[i],u[i]);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				chk(dp[j][k],dp[j][k-1]);
		for(auto &p1:nd1)
			for(auto &p2:nd2){
				int res=n;
				for(int k=1;k<K;k++)
					res=min(res,max(dp[p1][k],dp[p2][K-k]));
				res=max(res,val[p1][p2]),chk(ans,res);
			}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
		edge[i].clear(); 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
		Main();
	return 0;
}
