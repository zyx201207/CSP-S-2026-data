#include<bits/stdc++.h>
using namespace std;

const int MXN = 503 , MXM = 5e5+3 ;
const long long INF = 1e18 ;

vector<pair<int,int>> g[MXM];
int c,n,m,d,q,w[MXM];
long long dis[MXN][MXN],res;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int k,a,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dis[i][j]=INF;
	for(int i=1;i<=m;i++)
		for(pair<int,int> j:g[i])
			for(pair<int,int> k:g[i])
				dis[j.first][k.first]=min(dis[j.first][k.first],(long long)j.second+k.second);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	int u,v;
	while(q--){
		cin>>u>>v;
		res=INF;
		for(pair<int,int> i:g[u])
			for(pair<int,int> j:g[v])
				res=min(res,i.second+j.second+dis[i.first][j.first]);
		res+=w[u]+w[v];
		cout<<res<<"\n";
	}
	return 0;
}