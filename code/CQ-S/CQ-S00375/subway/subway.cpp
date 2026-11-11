#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,z[500010],f[510][510];
struct node{
	int to,vl;
};
vector<node>e[500510];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>z[i];
	for(int i=1;i<=n;i++){
		int k,u=m+i;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			e[v].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e17;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)e[i].size();i++){
			for(int k=j+1;k<(int)e[i].size();k++){
				int u=e[i][j].to,v=e[i][k].to,w=e[i][j].vl+e[i][k].vl;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e17;
		cin>>x>>y;
		for(int i=0;i<(int)e[x].size();i++){
			for(int j=0;j<(int)e[y].size();j++){
				int u=e[x][i].to,v=e[y][j].to,w=e[x][i].vl+e[y][j].vl;
				ans=min(ans,z[x]+z[y]+w+f[u][v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
