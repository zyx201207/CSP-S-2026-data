#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,K=23;
int C,n,m,D,q,w[M],d[M][K][2],c[M],k[M],f[N][N],ans,x,y;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i],f[i][i]=0;
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y,c[x]++;
			d[x][c[x]][0]=i,d[x][c[x]][1]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=c[i];j++){
			for(int l=j+1;l<=c[i];l++){
				int len=d[i][j][1]+d[i][l][1];
				int a=d[i][j][0],b=d[i][l][0];
				f[a][b]=f[b][a]=min(f[a][b],len);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
		}
	}
	while(q--){
		cin>>x>>y,ans=1e18;
		for(int i=1;i<=c[x];i++){
			for(int j=1;j<=c[y];j++){
				int len=d[x][i][1]+d[y][j][1];
				int a=d[x][i][0],b=d[y][j][0];
				ans=min(ans,f[a][b]+len);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
