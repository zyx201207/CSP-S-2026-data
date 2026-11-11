#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e4+5;
bool vis[M];
long long c,n,m,d,q,x,y,w[M],k[N];
int a[N][M],t[N][M];
struct node{
	long long xianlu,zhan;
	bool vis;
};
vector<node>G[M];
long long dfs(long long u,long long xl,long long z,bool ye){//4 1 3 0
	if(u==y)return 0;
	long long ans=LLONG_MAX;
	if(!ye){
		for(long long i=1,v;i<=k[xl];i++){
			v=a[xl][i];
			if(vis[v])continue;
			vis[v]=1;
			ans=min(ans,dfs(v,xl,i,1));
			vis[v]=0;
		}
	}
	if(ye){
		for(auto v:G[u]){
			if(v.vis)continue;
			v.vis=1;
			ans=min(ans,dfs(u,v.xianlu,v.zhan,0)+t[xl][z]+t[v.xianlu][v.zhan]);
			v.vis=0;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back((node){i,j,0});
		}
	}
	long long ans=LLONG_MAX;
	while(q--){
		cin>>x>>y;
		vis[x]=1;
		for(auto v:G[x]){
			v.vis=1;
			ans=min(ans,dfs(x,v.xianlu,v.zhan,0));
			v.vis=0;
		}
		vis[x]=0;
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
