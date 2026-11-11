#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define v first
#define w second
using namespace std;

const int N=505,M=6e5+5,K=25;

int c,n,m,d,q;
ll strt[M];
vector< pair<int,ll> > vec[M];
ll dis[N][N];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	rep(i,1,m) scanf("%lld",strt+i);
	rep(i,1,n) {
		int k;
		scanf("%d",&k);
		rep(j,1,k) {
			ll p,t;
			scanf("%lld%lld",&p,&t);
			vec[p].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	rep(u,1,n) dis[u][u]=0;
	rep(u,1,m) {
		if(vec[u].empty()) continue;
		for(auto p1:vec[u]) {
			for(auto p2:vec[u]) {
				int x=p1.v,y=p2.v;
				ll ww=p1.w+p2.w;
				dis[x][y]=min(dis[x][y],ww);
				dis[y][x]=min(dis[y][x],ww);
			}
		}
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(auto pp:vec[x])
			for(auto qq:vec[y])
				ans=min(ans,dis[pp.v][qq.v]+pp.w+qq.w);
		printf("%lld\n",ans+strt[x]+strt[y]);
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
