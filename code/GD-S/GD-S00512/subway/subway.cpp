#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=500,M=5e5,INF=1e18;
int c,n,m,d,q;
int w[M+5];
int f[N+5][N+5];
vector<pii> vec[M+5]; 
void chkmin(int &x,int y){
	x=(x>=y?y:x);
}
void Floyd(){
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				chkmin(f[i][j],f[i][k]+f[k][j]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			vec[x].emplace_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;++i){
		int len=vec[i].size()-1;
		for(int x=0;x<=len-1;++x)
			for(int y=x+1;y<=len;++y){
				int u=vec[i][x].first,v=vec[i][y].first,w=vec[i][x].second+vec[i][y].second;
				chkmin(f[u][v],w),chkmin(f[v][u],w);
			}
	}
	Floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(pii p:vec[x])
			for(pii q:vec[y])
				chkmin(ans,p.second+q.second+f[p.first][q.first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

