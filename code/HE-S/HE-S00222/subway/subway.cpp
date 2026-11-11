#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1100;
int g[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(g,0x3f,sizeof g);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		g[i][i+m]=g[i+m][i]=w;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			g[a+m][2*m+i]=g[2*m+i][a+m]=t;
		}
	}
	int z=2*m+n;
	for(int i=1;i<=z;i++){
		for(int j=1;j<=z;j++){
			for(int k=1;k<=z;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1;i<=z;i++){
		for(int j=1;j<=z;j++){
			for(int k=1;k<=z;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1;i<=z;i++){
		for(int j=1;j<=z;j++){
			for(int k=1;k<=z;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int s,e;cin>>s>>e;
		cout<<g[s][e]<<endl;
	}
	return 0;
}

