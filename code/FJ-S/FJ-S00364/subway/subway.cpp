#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
const int INF=0x3f3f3f;
int w[N],k[N],a[N][N],t[N][N];
int dist[N][N];
int g[N][N];
int b[1105];
int c,n,m,d,q,sum,maxans=-111,ans=0;
int main(){
	memset(dist,INF,sizeof(dist));
	memset(g,INF,sizeof(g));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cout<<k[i]<<"\n";
		if(k[i]<=2){
			cnt++;
		}
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cout<<a[i][j]<<" "<<t[i][j]<<"\n";
		//	t[a[i][j]]++;
			for(int l=1;l<j;l++){
				g[a[i][j]][a[i][l]]=min(t[i][j],g[a[i][j]][a[i][l]]);
				cout<<g[a[i][j]][a[i][l]]<<" ";
				g[a[i][l]][a[i][j]]=min(t[i][j],g[a[i][j]][a[i][l]]);
				cout<<g[a[i][l]][a[i][j]]<<"\n";
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int mid=1;mid<=m;mid++){
				if(g[i][mid]!=INF&&g[j][mid]!=INF&&){
					dist[i][j]=min(dist[i][j],dist[i][mid]+dist[j][mid]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dist[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
