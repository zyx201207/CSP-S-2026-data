#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e4+5;
int c,n,m,d,q,w[N],k[505],a[505][N],t[505][N],f[N];
int edge[1005][1005],dist[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	memset(edge,0x3f,sizeof edge);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k[i];j++)
			for(int l=1;l<=k[i];l++){
				if(a[i][j]==a[i][l]){
					edge[a[i][j]][a[i][l]]=0;
					continue;
				}
				edge[a[i][j]][a[i][l]]=min(edge[a[i][j]][a[i][l]],w[a[i][j]]+t[i][j]+t[i][l]+w[a[i][l]]);
			}
	for(int l=1;l<=m;l++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dist[i][j]=min(edge[i][j],edge[i][l]+edge[l][j]-2*w[l]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]<<"\n";
	}
	return 0;
}
