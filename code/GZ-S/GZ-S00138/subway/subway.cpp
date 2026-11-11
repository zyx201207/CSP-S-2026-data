//GZ-S00138 贵阳市第一中学 张轩睿 
#include <bits/stdc++.h>
#define int long long
#define mk(p1,p2) make_pair(p1,p2)
using namespace std;
const int N=510,M=5e5+10,INF=1e18; 
int c,n,m,d,q;
int w[N];
vector<pair<int,int>>a[M];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=INF;
	for (int i=1;i<=n;i++)
		dis[i][i]=0; 
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			for (int pos=0;pos<(int)a[x].size();pos++){
				int t1=a[x][pos].first,w1=a[x][pos].second;
				dis[t1][i]=min(dis[t1][i],w1+y);
				dis[i][t1]=min(dis[i][t1],w1+y);
			}
			a[x].push_back(mk(i,y));
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
	while (q--){
		int u,v,ans=INF;
		cin>>u>>v;
		for (int i=0;i<(int)a[u].size();i++){
			for (int j=0;j<(int)a[v].size();j++){
				int t1=a[u][i].first,t2=a[v][j].first;
				int w1=a[u][i].second,w2=a[v][j].second;
				ans=min(ans,w[u]+w[v]+w1+w2+dis[t1][t2]);
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
