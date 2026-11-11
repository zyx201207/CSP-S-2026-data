#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000005
#define inf 0x3f3f3f3f3f3f3f3fll
#define N 505
int c,n,m,d,q;
/*
n: 线路数
m：站数
d：max cross 
*/
ll w[M];
vector<pair<int,ll>> ds[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int x;ll t; cin>>x>>t;
			ds[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int x=1;x<=m;x++){
		for(int i=0;i<ds[x].size();i++){
			for(int j=i+1;j<ds[x].size();j++){
				dis[ds[x][i].first][ds[x][j].first]=dis[ds[x][j].first][ds[x][i].first]=min(dis[ds[x][i].first][ds[x][j].first],ds[x][i].second+ds[x][j].second);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v; cin>>u>>v;
		if(u==v){
			cout<<0<<'\n';
			continue;
		}
		ll mnd=inf;
		for(int i=0;i<ds[u].size();i++){
			for(int j=0;j<ds[v].size();j++){
				mnd=min(mnd,ds[u][i].second+dis[ds[u][i].first][ds[v][j].first]+ds[v][j].second);
			}
		}
		cout<<mnd+w[u]+w[v]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
