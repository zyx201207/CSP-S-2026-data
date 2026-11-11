#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+50,M=2e4+50,INF=1e18;
int c,n,m,d,q,x,y;
int w[M],a[N][M],k[N],t[N][M],dist[N][M],f[N][N];
vector<int> ve[M];

inline void solve(){
	int ans=INF;
	cin>>x>>y;
	for(int i=0;i<ve[x].size();i++){
		for(int j=0;j<ve[y].size();j++){
			if(ve[x][i]==ve[y][j]) ans=min(ans,w[x]+w[y]+dist[ve[x][i]][x]+dist[ve[y][j]][y]);
			else ans=min(ans,w[x]+w[y]+dist[ve[x][i]][x]+dist[ve[y][j]][y]+f[ve[x][i]][ve[y][j]]);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ve[a[i][j]].push_back(i);
			dist[i][a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			x=a[i][j],y=t[i][j];
			for(auto u:ve[x]){
				if(i==u) continue;
				f[i][u]=min(f[i][u],y+dist[u][x]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||j==k) continue;
				if(f[i][k]==INF||f[k][j]==INF) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--) solve();
	return 0;
}
