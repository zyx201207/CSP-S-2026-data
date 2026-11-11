#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,c,dist[505];
int a[1005];
struct edge {
	int to, y;
};
vector<edge> g[1005];
int f[1005][1005],ww[1005],w[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>ww[i];
			g[i+500].push_back({a[i],ww[i]+w[i]});
			g[a[i]].push_back({i+500,ww[i]+w[i]});
		}
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			f[j][i]=f[i][j]=g[i][j].y;
		}
	}
	for(int k=1;k<=n+m;k++)
		for(int i=1;i<=n+m;i++)
			for(int j=1;j<=n+m;j++)
				if(f[i][k]&&f[k][j])
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<f[u][v]<<'\n';
	}
	return 0;
}
