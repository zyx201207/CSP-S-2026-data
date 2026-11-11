#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=5e2+5,M=5e5+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
int c,n,m,d,q,x,y,w[M],k[N],dis[N][N];
vector<pair<int,int>>g[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			g[x].push_back({i,y});
//			cout<<i<<" "<<x<<" "<<y<<endl;
		}
	}
	memset(dis,INF,sizeof dis);
	for(int i=1;i<=n;i++)
		dis[i][i] = 0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)g[i].size();j++)
			for(int k=0;k<j;k++){
				pair<int,int>p1=g[i][j],p2=g[i][k];
				dis[p1.first][p2.first] = min(dis[p1.first][p2.first],p1.second+p2.second);
				dis[p2.first][p1.first] = min(dis[p2.first][p1.first],p1.second+p2.second);
//				cout<<i<<" "<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<(j==n?endl:' ');
	while(q--){
		cin>>x>>y;
		int ans=INF*INF;
		for(auto u:g[x])
			for(auto v:g[y])
				ans = min(ans,w[x]+w[y]+u.second+v.second+dis[u.first][v.first])/*cout<<x<<" "<<y<<" "<<u.first<<" "<<u.second<<" "<<v.first<<" "<<v.second<<endl*/;
		cout<<ans<<endl;
	}
	return 0;
}

