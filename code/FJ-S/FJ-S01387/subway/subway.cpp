#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000000ll;
const long long N=505,M=500005;
vector<pair<long long,long long>>vec[M];
long long c,n,m,d,q,w[M],dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;++i)cin>>w[i];
	for(long long i=1;i<=n;++i){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;++j){
			long long x,y;
			cin>>x>>y;
			vec[x].emplace_back(make_pair(i,y));
		}
	}
	for(long long i=1;i<=n;++i)
		for(long long j=1;j<=n;++j)dis[i][j]=inf;
	for(long long i=1;i<=m;++i)
		for(auto t:vec[i])
			for(auto p:vec[i])dis[t.first][p.first]=min(dis[t.first][p.first],t.second+p.second);
	for(long long i=1;i<=n;++i)dis[i][i]=0;
	for(long long k=1;k<=n;++k)
		for(long long i=1;i<=n;++i)
			for(long long j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		long long u,v,ans=inf;
		cin>>u>>v;
		for(auto t:vec[u])
			for(auto p:vec[v])ans=min(ans,dis[t.first][p.first]+t.second+p.second);
		cout<<ans+w[u]+w[v]<<"\n";
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
*/
