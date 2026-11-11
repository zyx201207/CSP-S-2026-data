#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e2+10,maxm=5e5+10,inf=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>>G[maxm];
int w[maxm],f[maxn][maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int u=1;u<=m;u++)cin>>w[u];
	for(int i=1;i<=n;i++){
		int k,lst=0;cin>>k;
		while(k--){
			int u,w;cin>>u>>w;
			G[u].push_back({i,w});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int u=1;u<=n;u++)f[u][u]=0;
	for(int i=1;i<=m;i++)
		for(auto [u,wu]:G[i])
			for(auto [v,wv]:G[i])
				f[u][v]=min(f[u][v],wu+wv);
	for(int k=1;k<=n;k++)
		for(int u=1;u<=n;u++)
			if(f[u][k]!=+inf)for(int v=1;v<=n;v++)
				f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
	while(q--){
		int s,t;cin>>s>>t;
		int res=+inf;
		for(auto [u,wu]:G[s])
			for(auto [v,wv]:G[t])
				res=min(res,wu+f[u][v]+wv);
		cout<<w[s]+res+w[t]<<'\n';
	}
	return 0;
}
