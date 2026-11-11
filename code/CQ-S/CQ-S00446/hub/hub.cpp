/*
T1,T2,T3 一定要过啊
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,k,ans,c,sz[1000005],mx[1000005];
vector<int>g[1000005];
int f[105][105][105][3],f2[105][105][3],f3[105][105];
void dfs(int u,int fa){
	memset(f[u],0x3f,sizeof(f[u]));
	memset(f3[u],0x3f,sizeof(f3[u]));
	sz[u]=1;
	f[u][1][0][1]=0;
	f[u][0][0][0]=0;
	mx[u]=1;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		memcpy(f2,f[u],sizeof(f2));
		memset(f[u],0x3f,sizeof(f[u]));
		for(int i=0;i<=sz[u];i++){
			for(int j=0;j<=sz[v]&&i+j<=k;j++){
				for(int x=0;x<=mx[u];x++){
					if(j==0)f[u][i+j][max(x,mx[v]+1)][0]=min(f[u][i+j][max(x,mx[v]+1)][0],max(f2[i][x][0],mx[v]+x+1));
				}
				for(int y=0;y<=mx[v];y++){
					if(i==0)f[u][i+j][max(mx[u],y+1)][0]=min(f[u][i+j][max(mx[u],y+1)][0],max(mx[u]+y+1,min(f[v][j][y][0],f[v][j][y][1])));
					f[u][i+j][0][2]=min(f[u][i+j][0][2],max(f2[i][0][1],max(f[v][j][y][0],y+1)));
				}
				f[u][i+j][0][1]=min(f[u][i+j][0][1],max(f2[i][0][1],f[v][j][0][1]));
				if(j==0)f[u][i+j][0][1]=min(f[u][i+j][0][1],max(f2[i][0][1],mx[v]+1));

				f[u][i+j][0][2]=min(f[u][i+j][0][2],max(f2[i][0][2],f[v][j][0][1]));
				if(j==0)f[u][i+j][0][2]=min(f[u][i+j][0][2],max(f2[i][0][2],mx[v]+1));

				for(int x=0;x<=mx[u];x++){
					for(int y=0;y<=mx[v];y++){
						f3[u][i+j]=min(f3[u][i+j],max(max(f[u][i][x][0],x),max(f[v][i][y][0],y+1)));
					}
				}
			}
		}
		sz[u]+=sz[v];
		mx[u]=max(mx[u],mx[v]+1);
	}
}
void dfs2(int u,int fa,int t){
	int a=-1e15,b=-1e15;
	for(int v:g[u]){
		if(v==fa)continue;
		if(mx[v]>a)b=a,a=mx[v];
		else b=max(b,mx[v]);
	}
	a++,b++;
	ans=min(ans,t+min(f[u][k][0][2],f3[u][k]));
	for(int v:g[u]){
		if(v==fa)continue;
		dfs2(v,u,max(t+1,a==mx[v]+1?b:a));
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14){
			if(k>=(n-1)/2)cout<<(k!=n)<<" ";
			else cout<<((n-1)/2-k+3)/4+1<<"\n";
			continue;
		}
		ans=1e18;
		dfs(1,-1);
		dfs2(1,-1,0);
		cout<<ans<<'\n';
	}
	return 0;
}//rp++
/*
dsu on tree???
*/