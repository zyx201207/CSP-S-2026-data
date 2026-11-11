#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> pint;
const int N=505,M=5e5+114,D=22;
int w[M],n,m,d,q;
pint to[M][D];
int len[M];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cid;
	cin >> cid >> n >> m >> d >> q;
	for(int i=1;i<=m;++i) cin >> w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin >> k;
		while(k--){
			int a,t;
			cin >> a >> t;
			to[a][++len[a]]=pint(i,t);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dis[i][j]=Inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=len[i];++j){
			for(int k=1;k<=len[i];++k){
				dis[to[i][j].first][to[i][k].first]=min(dis[to[i][j].first][to[i][k].first],to[i][j].second+to[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		int ans=Inf;
		for(int i=1;i<=len[u];++i){
			for(int j=1;j<=len[v];++j){
				ans=min(ans,to[u][i].second+dis[to[u][i].first][to[v][j].first]+to[v][j].second);
			}
		}
		ans+=w[u]+w[v];
		cout << ans << '\n';
	}
	return 0;
}
