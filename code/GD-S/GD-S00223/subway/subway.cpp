#include<bits/stdc++.h>
#define int long long
using namespace std;

const int _=5e5+5,inf=1e18;

int n,m;
int w[_],d[500][500];

vector<pair<int,int>>e[_];

void calc(int u){
	for(int i=0;i<e[u].size();i++)for(int j=i+1;j<e[u].size();j++){
		int v1=e[u][i].first,v2=e[u][j].first,w=e[u][i].second+e[u][j].second;
		d[v1][v2]=min(d[v1][v2],w);
		d[v2][v1]=min(d[v2][v1],w);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C,D,Q;
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i^j)d[i][j]=inf;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)calc(i);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int u,v;Q--;){
		cin>>u>>v;
		int res=inf;
		for(int i=0;i<e[u].size();i++)for(int j=0;j<e[v].size();j++)res=min(res,e[u][i].second+d[e[u][i].first][e[v][j].first]+e[v][j].second);
		cout<<res+w[u]+w[v]<<'\n';
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

32
17
*/
