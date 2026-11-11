#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;
const int N=500+9;//QAQ
const int M=5e5+9;
const int D=25;
const ll INF=(1<<30);
ll NO_USE;
ll n,m,d,q;
ll out[N];//出口步行用时 
/*这样就不会爆炸了:P*/
unordered_map<ll,ll> dist[N][N];
unordered_map<ll,ll> hole[N];//换乘代价 
//ll dist[N][N][D];
ll ans[N][N];
//ll hole[N][D];//换乘代价 
void flyd() {
	for(ll x=1;x<=m;x++) {
		for(ll k=1;k<=n;k++) {
			for(ll u=1;u<=n;u++) {
				for(ll v=1;v<=n;v++) {
					ll cost=dist[u][k][x]+dist[k][v][x]-2*hole[k][x];//没换乘，去除过路 
					dist[u][v][x]=min(dist[u][v][x],cost);
					if(hole[k][x]!=INF) {
						for(ll y=1;y<=m;y++) {
							if(x==y) continue;
							ll cost=dist[u][k][y]+dist[k][v][x];
							dist[u][v][x]=min(dist[u][v][x],cost);
						}
					}
//					cout<<u<<"->"<<v<<"("<<x<<")"<<dist[u][v][x]<<"\n";
					ans[u][v]=min(ans[u][v],dist[u][v][x]);
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>NO_USE>>m>>n>>NO_USE>>q;
	for(ll u=1;u<=n;u++) {
		for(ll v=1;v<=n;v++) {
			ans[u][v]=INF;
			for(ll i=1;i<=m;i++) dist[u][v][i]=INF;
		}
	}
	for(ll i=1;i<=n;i++) scanf("%lld",&out[i]);
	for(ll i=1;i<=m;i++) {
		ll k;
		ll a,t;
		ll laA=-1,laT;
		scanf("%lld",&k);
		while(k--) {
			scanf("%lld%lld",&a,&t);
			hole[a][i]=t;
			if(laA!=-1) {
				dist[a][laA][i]=dist[laA][a][i]=t+laT;
				ans[a][laA]=ans[laA][a]=min(ans[a][laA],t+laT);
			}
			laA=a,laT=t;
		}
	}
	flyd();
//	for(ll u=1;u<=n;u++) {
//		for(ll v=u+1;v<=n;v++) {
//			cout<<u<<"-"<<v<<": "<<ans[u][v]<<"\n";
//		}
//	}
	while(q--) {
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",ans[x][y]+out[x]+out[y]);
	}
	return 0;
} 

/*
几乎一定是dp....2e5的q 
QWQ

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
