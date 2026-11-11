#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010,M=510,K=21;
int g[M][M],e[N][K],d[N],op,n,m,q,t[N][K],w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>op>>n>>m;
	cin>>op>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) g[i][j]=LONG_LONG_MAX/2;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y,k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			e[x][++d[x]]=i;
			t[x][d[x]]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d[i];j++){
			for(int k=j+1;k<=d[i];k++){
				g[e[i][j]][e[i][k]]=g[e[i][k]][e[i][j]]=min(g[e[i][j]][e[i][k]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		int ans=LONG_LONG_MAX/2;
		cin>>x>>y;
		for(int j=1;j<=d[x];j++){
			for(int k=1;k<=d[y];k++){
				ans=min(ans,t[x][j]+g[e[x][j]][e[y][k]]+t[y][k]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}