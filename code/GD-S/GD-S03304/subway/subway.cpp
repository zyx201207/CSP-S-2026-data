#include<bits/stdc++.h>
using namespace std;
typedef long long llong;
typedef pair<int,int> pii;
const llong inf=0x3fffffffffffffffll;
const int maxn=505,maxm=5e5+50;
int c,n,m,d,q,w[maxm];
vector<pii> g[maxm];
llong dist[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=m;++i){
		g[i].reserve(d);
	}
	for(int i=1;i<=n;++i){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		fill(dist[i]+1,dist[i]+n+1,inf);
		dist[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		int sz=g[i].size();
		for(int j=1;j<sz;++j){
			int u=g[i][j].first,wu=g[i][j].second;
			for(int k=0;k<j;++k){
				int v=g[i][k].first,wv=g[i][k].second;
				dist[v][u]=dist[u][v]=min<llong>(dist[u][v],wu+wv);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int k=1;k<=n;++k){
			for(int j=1;j<=n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		llong ans=inf;
		for(pii ex:g[x]){
			int u=ex.first,wu=ex.second;
			for(pii ey:g[y]){
				int v=ey.first,wv=ey.second;
				ans=min(ans,wu+wv+dist[u][v]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
