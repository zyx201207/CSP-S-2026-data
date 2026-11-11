#include<bits/stdc++.h>
#define int long long
#define N 500005 
using namespace std;
int w[N];
vector<pair<int,int>>ve[N];
int f[505][505];
void solve(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,v;
			cin>>x>>v;
			ve[x].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=1e18;
	for(int i=1;i<=n;i++)
	f[i][i]=0;
	for(int i=1;i<=m;i++){
		int vesize=ve[i].size();
		for(int ui=0;ui<vesize;ui++)
		for(int vi=0;vi<vesize;vi++){
			int u=ve[i][ui].first,v=ve[i][vi].first;
			int w=ve[i][ui].second+ve[i][vi].second;
			f[u][v]=min(f[u][v],w);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(auto i:ve[u])
		for(auto j:ve[v])
		ans=min(ans,f[i.first][j.first]+i.second+j.second+w[u]+w[v]);
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
