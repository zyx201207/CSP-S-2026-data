#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=600,M=6*1e5;
const ll inf=1e18;
ll d[N][N];
ll x[M],y[M];
ll w[M],K[N];
ll c,n,m,D,q;
ll ans[M];

struct node{
	int a=0;
	ll t=0;
};
vector<node> e[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&D,&q);
//	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
//		cin>>K[i];
		scanf("%lld",K+i);
		for(int j=1;j<=K[i];j++){
			ll at,tt;
//			cin>>at>>tt;
			scanf("%lld %lld",&at,&tt);
			e[at].push_back({i,tt});
		}
	}
	for(int i=1;i<=q;i++){
//		cin>>x[i]>>y[i];
		scanf("%lld %lld",x+i,y+i);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=inf;
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;++i){
		int sz=e[i].size();
		for(int j=0;j<sz;++j){
			for(int k=j+1;k<sz;++k){
				int pj=e[i][j].a;
				ll tj=e[i][j].t;
				int pk=e[i][k].a;
				ll tk=e[i][k].t;
				d[pj][pk]=min(d[pj][pk],tj+tk);
				d[pk][pj]=min(d[pk][pj],tj+tk);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans[i]=inf;
		for(int j=0;j<e[x[i]].size();j++){
			for(int k=0;k<e[y[i]].size();k++){
				node pj=e[x[i]][j];
				node pk=e[y[i]][k];
				ans[i]=min(ans[i],d[pj.a][pk.a]+pj.t+pk.t+w[x[i]]+w[y[i]]);
			}
		}
	}
	for(int i=1;i<=q;i++){
//		cout<<ans[i]<<endl;
		printf("%lld\n",ans[i]);
	}
	
	return 0;
}
