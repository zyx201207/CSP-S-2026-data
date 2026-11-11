#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
const int N=5e5+10;
using ll=long long;
ll w[N];
vector<pair<int,ll> > s[N];
ll dis[510][510],g[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int a;
			ll t;
			scanf("%d%lld",&a,&t);
			s[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		g[i][j]=dis[i][j]=1e17;
		if(i==j)g[i][j]=dis[i][j]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<s[i].size()-1;++j)
			for(int k=j+1;k<s[i].size();++k){
				int u=s[i][j].first,v=s[i][k].first;
				g[u][v]=g[v][u]=min(g[u][v],s[i][j].second+s[i][k].second);
			}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(;q;--q){
		int st,ed;
		scanf("%d%d",&st,&ed);
		ll ans=1e18;
		for(auto i:s[st])
			for(auto j:s[ed]){
				ans=min(ans,i.second+j.second+g[i.first][j.first]);
			}
		printf("%lld\n",ans+w[st]+w[ed]);
	}
	return 0;
}
