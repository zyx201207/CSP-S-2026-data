#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=505,M=5e5+5;
const i64 inf=1e18;
int cid,n,m,d,q;
i64 a[M],dis[N][N];
vector<pair<int,i64>>G[N],S[M];
int main(){
	int C=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	for(int i=1,k;i<=n;++i){
		cin>>k;
		G[i].resize(k);
		for(auto&[u,w]:G[i]){
			cin>>u>>w;
			S[u].emplace_back(i,w);
		}
	}
	for(int u=1;u<=n;++u){
		fill(dis[u]+1,dis[u]+n+1,inf);
		dis[u][u]=0;
		for(auto[t,w1]:G[u]){
			for(auto[v,w2]:S[t]){
				dis[u][v]=min(dis[u][v],w1+w2);
			}
		}
	}
	for(int t=1;t<=n;++t){
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				dis[u][v]=min(dis[u][v],dis[u][t]+dis[t][v]);
			}
		}
	}
	for(int x,y;q--;){
		cin>>x>>y;
		i64 ans=inf;
		for(auto[u,w1]:S[x]){
			for(auto[v,w2]:S[y]){
				ans=min(ans,a[x]+a[y]+w1+w2+dis[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	cerr<<"Time:"<<1.*(clock()-C)/CLOCKS_PER_SEC<<"s\n";
}