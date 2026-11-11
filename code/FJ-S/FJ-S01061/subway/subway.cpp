#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=3e3+5,inf=0x3f3f3f3f;
int c,n,m,d,q;
int w[M],a[M],t[M],g[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,inf,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				g[a[u]][a[v]]=g[a[v]][a[u]]=min(g[a[u]][a[v]],t[u]+t[v]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=i+1;j<=m;j++){
//			cout<<g[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(i!=k&&j!=k){
					g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+g[x][y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


32
17
*/
