#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500500],k,a[550][500500],t[500500][550],Map[550][550],dss,dcx,s,e,g[550][550];
void F(){
	for (int k=1;k<=m;k++){
		for (int x=1;x<=m;x++){
			for (int y=1;y<=m;y++){
				g[x][y]=min(g[x][y],g[x][k]+g[k][y]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f3f3f3f,sizeof(g));
	memset(t,0x3f3f3f3f,sizeof(t));
	memset(Map,0x3f3f3f3f,sizeof(Map));
	memset(a,0,sizeof(a));
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>dss;
			a[i][dss]=1;
			cin>>dcx;
			t[dss][i]=dcx;
		}
	}
	for (int u=1;u<=n;u++){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				if (a[u][i]==1 && a[u][j]==1){
					Map[i][j]=min(Map[i][j],t[i][u]+t[j][u]);
					g[i][j]=Map[i][j];
				}
			}
		}
	}
	F();
	for (int i=1;i<=q;i++){
		cin>>s>>e;
		if (s==e) cout<<0<<'\n';
		else cout<<g[s][e]<<'\n';
	}
	return 0;
}
