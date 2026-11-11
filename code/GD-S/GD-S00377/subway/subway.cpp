#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5,M=505;
int c,n,m,d,q,a[N],f[M][M];
vector<pir>e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			e[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		for(int j=i+1;j<=n;j++)
			f[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		sort(e[i].begin(),e[i].end());
		for(int j=0;j<e[i].size();j++)
			for(int k=j+1;k<e[i].size();k++){
				f[e[i][j].fi][e[i][k].fi]=min(f[e[i][j].fi][e[i][k].fi],e[i][j].se+e[i][k].se);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<k;i++)
			for(int j=k+1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,res=1e18;
		cin>>x>>y;
		for(pir i:e[x])
			for(pir j:e[y]){
				int xx=i.fi,yy=j.fi;
				if(xx>yy)swap(xx,yy);
				res=min(res,f[xx][yy]+i.se+j.se);
			}
		cout<<res+a[x]+a[y]<<'\n';
	}
	return 0;
}

