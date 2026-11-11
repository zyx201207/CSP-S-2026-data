#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=510;
const int M=500010;
const ll inf=1LL<<60;

int c,n,m,d,q;
ll dis[N][N],dis2[M+N],e2[N][N],aw[M];
vector<pair<int,ll>> e[N+M];
set<pair<ll,int>> se;

//inline void dij(int bg){
//	for(int i=1;i<=n+m;i++)
//		dis2[i]=inf;
//	dis2[m+bg]=0;
//	se.insert({0LL,m+bg});
//	while(!se.empty()){
//		auto u=se.begin()->second;
//		se.erase(se.begin());
//		for(auto e_:e[u]){
//			int v=e_.first;
//			ll w=e_.second;
//			if(dis2[v]>dis2[u]+w){
//				se.erase({dis2[v],v});
//				dis2[v]=dis2[u]+w;
//				se.insert({dis2[v],v});
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//		dis[bg][i]=dis2[m+i];
//}

inline void dij2(int bg){
	for(int i=1;i<=n;i++)
		dis[bg][i]=inf;
	dis[bg][bg]=0;
	se.insert({0LL,bg});
	while(!se.empty()){
		auto u=se.begin()->second;
		se.erase(se.begin());
		for(int v=1;v<=n;v++){
			if(dis[bg][v]>dis[bg][u]+e2[u][v]){
				se.erase({dis[bg][v],v});
				dis[bg][v]=dis[bg][u]+e2[u][v];
				se.insert({dis[bg][v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&aw[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int v;
			ll w;
			scanf("%d%lld",&v,&w);
			e[m+i].push_back({v,w});
			e[v].push_back({m+i,w});
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			e2[i][j]=inf;
		e2[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto e_1:e[i]){
			for(auto e_2:e[i]){
				e2[e_1.first-m][e_2.first-m]=min(e2[e_1.first-m][e_2.first-m],e_1.second+e_2.second);
				e2[e_2.first-m][e_1.first-m]=min(e2[e_2.first-m][e_1.first-m],e_1.second+e_2.second);
			}
		}
	}

//	for(int i=1;i<=n;i++)
//		dij(i);
	for(int i=1;i<=n;i++)
		dij2(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			printf("%lld ",dis[i][j]);
//		puts("");
//	}

	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		ll ans=inf;
		for(auto e_1:e[s]){
			for(auto e_2:e[t])
				ans=min(ans,dis[e_1.first-m][e_2.first-m]+e_1.second+e_2.second);
		}
//		printf("%lld\n",ans);
		printf("%lld\n",ans+aw[s]+aw[t]);
	}
}

// jia you ! OIer men , chang zheng yong yuan zai lu shang !
