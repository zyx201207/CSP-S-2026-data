#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=5e5+10;
const int N=210;
int w[M],k[N],a[N][M],t[N][M],line[M][N];
int vis[M];
long long dfs(int u,int l,int y,long long tt){
	if(u==y){
		return tt+t[l][y]+w[y];
	}
	for(int i=1;i<=d;i++){
		int ul=line[u][i];
		if(ul==l || ul==0) continue; 
		for(int i=1;i<=k[ul];i++){
			int v=a[ul][i];
			if(vis[v]==1) continue;
			vis[v]=1;
			return dfs(v,l,y,tt);
			vis[v]=0;
		}
	}
	for(int i=1;i<=k[l];i++){
		int v=a[l][i];
		if(vis[v]==1) continue;
		vis[v]=1;
		return dfs(v,l,y,tt);
		vis[v]=0;
	}
	return tt;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int cnt=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			line[a[i][j]][++cnt]=i;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		
		long long ans=dfs(x,line[x][1],y,w[x]+t[line[x][1]][x]);
		cout<<ans<<"\n";
	}
	return 0;
}
