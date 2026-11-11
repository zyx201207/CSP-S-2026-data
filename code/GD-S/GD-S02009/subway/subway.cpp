#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=5e5+10,M=510;
int n,m,q,d,f[M][M],w[N],b[N];
vector<pair<int,int> > a[N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int C;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>b[i];
		for(int j=1;j<=b[i];++j){
			int x,y;
			cin>>x>>y;
			a[x].push_back(make_pair(i,y));
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i)for(int j=0;j<a[i].size();++j)for(int k=0;k<a[i].size();++k)if(j^k)f[a[i][j].first][a[i][k].first]=min(f[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second),f[a[i][k].first][a[i][j].first]=min(f[a[i][k].first][a[i][j].first],a[i][j].second+a[i][k].second);
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j)cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<a[u].size();++i)for(int j=0;j<a[v].size();++j)ans=min(ans,a[u][i].second+a[v][j].second+f[a[u][i].first][a[v][j].first]);
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}

