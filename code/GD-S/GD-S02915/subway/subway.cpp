#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=505,M=5e5+5,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[N],w[M],f[N][N];
vector<pair<int,int> >a[N],b[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];f[i][i]=0;
		for(int j=0;j<k[i];j++){
			int x,y;cin>>x>>y;
			a[i].emplace_back(x,y);
			b[x].emplace_back(i,y);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<a[i].size();j++){
			int u=a[i][j].fi,t1=a[i][j].se;
			for(int k=0;k<b[u].size();k++){
				int v=b[u][k].fi,t2=b[u][k].se;
				f[i][v]=f[v][i]=min(f[i][v],t1+t2);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(f[i][k]==inf)continue;
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	while(q--){
		int u,v,ans=inf;cin>>u>>v;
		for(int i=0;i<b[u].size();i++)
			for(int j=0;j<b[v].size();j++)
				ans=min(ans,b[u][i].se+f[b[u][i].fi][b[v][j].fi]+b[v][j].se);
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}
