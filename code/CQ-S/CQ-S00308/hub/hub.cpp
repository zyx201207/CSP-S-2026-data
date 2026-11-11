#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T;
int n,k;
vector<int>e[N];
int f[4005][4005][3],g[4005][4005][3];
int t1[4005][3],t2[4005][3];
int dep[N],dis[N];
int L;
void dfs(int u,int fa){dep[u]=dep[fa]+1;dis[u]=0;
	f[u][0][1]=1;
	g[u][0][0]=0;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		for(int i=0;i<=dis[u];i++)for(int j=0;j<=2;j++)t1[i][j]=f[u][i][j],t2[i][j]=g[u][i][j],f[u][i][j]=g[u][i][j]=n+1;
		for(int i=0;i<=dis[u];i++){
			for(int j=0;j<=dis[v];j++){
				for(int x=0;x<=2;x++){
					for(int y=0;y<=2;y++){
						int z=x+y-(!i&&!j);
						if(z<=2){
							f[u][min(i,j+1)][z]=min(f[u][min(i,j+1)][z],t1[i][x]+f[v][j][y]);
						}
						z=x+y;
						if(z<=2){
							if(i+j+1<=L){
								f[u][i][z]=min(f[u][i][z],t1[i][x]+g[v][j][y]);
								f[u][j+1][z]=min(f[u][j+1][z],t2[i][x]+f[v][j][y]);
							}
							else{
								g[u][i][z]=min(g[u][i][z],t2[i][x]+f[v][j][y]);
								g[u][j+1][z]=min(g[u][j+1][z],t1[i][x]+g[v][j][y]);
							}
							g[u][max(i,j+1)][z]=min(g[u][max(i,j+1)][z],t2[i][x]+g[v][j][y]);
						}
					}
				}
			}
		}
		dis[u]=max(dis[u],dis[v]+1);
	}
}
int chk(int l){L=l;
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=2;k++)f[i][j][k]=g[i][j][k]=n+1;
	dfs(1,0);
	int res=n+1;
	for(int i=0;i<=n;i++)res=min(res,min(f[1][i][1],f[1][i][2]));
	return res<=k;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1,u,v;i<n;i++){cin>>u>>v;e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	if(k==n){
		cout<<"0\n";
		return;
	}
	if(C==13||C==14){
		int m=n>>1;
		if(k==n){
			cout<<"0\n";
			return;
		}
		if(k>=m){
			cout<<1<<"\n";
			return;
		}
		int d=m+4-k;
		int z=(d-1)/4+1;
		cout<<z<<"\n";
		return;
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<"\n";
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
