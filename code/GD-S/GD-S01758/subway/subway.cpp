#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,q,w[N];
ll f[510][510];
vector<pair<int,int> > g[N]; //g->µã 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=1e18;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int a=g[i][j].first,b=g[i][k].first,x=g[i][j].second,y=g[i][k].second;
				f[a][b]=min(f[a][b],0ll+x+y);
				f[b][a]=min(f[b][a],0ll+x+y);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++) ans=min(ans,f[g[x][i].first][g[y][j].first]+g[x][i].second+g[y][j].second);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
