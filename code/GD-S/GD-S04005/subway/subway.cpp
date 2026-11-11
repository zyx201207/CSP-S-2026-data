#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=510,maxm=5e5+10;

int c,n,m,d,q,w[maxm];
ll f[maxn][maxn];
vector<pii> e[maxm],pos[maxn];

inline void calc(){
	rep(i,1,n)
		rep(j,1,n)
			if(i!=j) f[i][j]=1e18;
	rep(i,1,n){
		for(auto [u,t1]:pos[i]){
			for(auto [v,t2]:e[u]){
				f[i][v]=min(f[i][v],1ll*(t1+t2));
				f[v][i]=min(f[v][i],1ll*(t1+t2));
			}
		}
	}	
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
}

inline void solve(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	rep(i,1,m) scanf("%d",&w[i]);
	rep(i,1,n){
		int k;
		scanf("%d",&k);
		while(k--){
			int u,t;
			scanf("%d%d",&u,&t);
			e[u].push_back({i,t});
			pos[i].push_back({u,t});
		}
	}
//	puts("E");
//	rep(i,1,m) printf("%d%c",e[i].size()," \n"[i==m]);
	calc();
//	rep(i,1,n)
//		rep(j,1,n)
//			printf("%lld%c",f[i][j]," \n"[j==n]);
	rep(i,1,q){
		int u,v;
		scanf("%d%d",&u,&v);
		ll res=1e18;
		for(auto [p1,t1]:e[u]){
			for(auto [p2,t2]:e[v]){
//				printf("%d %d %d %d %lld\n",p1,p2,t1,t2,f[p1][p2]);
				res=min(res,t1+t2+f[p1][p2]);
			}
		}
		printf("%lld\n",res+w[u]+w[v]);
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
//	scanf("%d",&_);
	while(_--) solve();
}

