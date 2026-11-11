#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int INF=(1LL<<31)-1;
int w[N],a[505][25],t[505][25],k[505],g[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) g[i][j]=INF;
	for(int i=1;i<=n;i++){
		for(int x=1;x<=k[i];x++){
			for(int y=1;y<=k[i];y++){
				int u=a[i][x],v=a[i][y];
				if(u!=v) g[u][v]=min(g[u][v],t[i][x]+t[i][y]);
			}
		}
	}
	for(int z=1;z<=m;z++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(g[i][z]!=INF&&g[z][j]!=INF&&i!=j){
					if(g[i][z]+g[z][j]<g[i][j]){
						g[i][j]=g[i][z]+g[z][j];
					}
				}
			}
		}
	}
	int f,l;
	for(int i=1;i<=q;i++){
		cin>>f>>l;
		cout<<g[f][l]+w[f]+w[l]<<'\n';
	}
	return 0;
}

