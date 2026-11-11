#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,w[500010],dis[510][510];
vector<pair<ll,ll>>e[500010],g[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>n>>m>>d>>q;memset(dis,0x3f,sizeof dis);for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;e[a].push_back({i,t}),g[i].push_back({a,t});
		}
		sort(g[i].begin(),g[i].end());
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		for(auto it1=g[i].begin(),it2=g[j].begin();it1!=g[i].end();it1++){
			while(it2!=g[j].end()&&it1->first>it2->first)it2++;
			if(it2!=g[j].end()&&it2->first==it1->first)dis[i][j]=min(dis[i][j],it1->second+it2->second);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		ll u,v,ans=0x3f3f3f3f3f3f3f3f;cin>>u>>v;
		for(auto it1:e[u])for(auto it2:e[v])ans=min(ans,w[u]+w[v]+dis[it1.first][it2.first]+it1.second+it2.second);
		cout<<ans<<'\n';
	}
}
