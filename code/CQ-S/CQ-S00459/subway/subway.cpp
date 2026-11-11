#include<bits/stdc++.h>
using namespace std;
namespace zjp{
	#define int long long 
	const int N=500,M=5e5,D=20,INF=1e18;
	int C,n,m,d,q;
	int w[M+5],len[M+5];
	int a[D+5][M+5],b[D+5][M+5];
	//
	int f[N+5][N+5];
	signed main(){
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>C>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int cnt,x,y;
			cin>>cnt;
			while(cnt--){
				cin>>x>>y;
				++len[x];
				a[len[x]][x]=i;
				b[len[x]][x]=y;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				f[i][j]=INF;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=len[i];j++){
				int x=a[j][i];
				for(int k=1;k<=len[i];k++){
					int y=a[k][i];
					f[x][y]=min(f[x][y],b[j][i]+b[k][i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				}
			}
		}
		int x,y;
		while(q--){
			cin>>x>>y;
			int ans=INF;
			for(int i=1;i<=len[x];i++){
				for(int j=1;j<=len[y];j++){
					ans=min(ans,b[i][x]+b[j][y]+f[a[i][x]][a[j][y]]);
				}
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
		return 0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return zjp::main();
}
