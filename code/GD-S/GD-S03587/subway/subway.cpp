#include<bits/stdc++.h>
#define int long long
using namespace std;
//bool st;
const int N = 700100;
int c,n,m,d,q;
int w[N],k[510],sz[N];
int path[510][510];
vector <int> sub[N],tim[N];
//bool en;
signed main(){
//	cout<<(&en-&st)/1024/1024;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		sub[i].push_back(0);
		tim[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ta,tt;
			cin>>ta>>tt;
			sub[ta].push_back(i);
			tim[ta].push_back(tt);
			sz[ta]++;
		}
	}
	memset(path,61,sizeof(path));
	for(int i=1;i<=n;i++) path[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sz[i];j++){
			for(int k=j+1;k<=sz[i];k++){
				int u=sub[i][j];
				int v=sub[i][k];
				path[u][v]=min(path[u][v],tim[i][j]+tim[i][k]);
				path[v][u]=path[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
			}
		}
	}
	//cout<<path[1][2]<<'\n';
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int res=1e18;
		for(int j=1;j<=sz[x];j++){
			for(int k=1;k<=sz[y];k++){
				int u=sub[x][j];
				int v=sub[y][k];
				if(res>path[u][v]+tim[x][j]+tim[y][k]) res=path[u][v]+tim[x][j]+tim[y][k];
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
