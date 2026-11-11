#include<bits/stdc++.h>
using namespace std;bool Mbe;
namespace MAOJUN{

typedef long long ll;
#define eb emplace_back
const int N=505,M=5e5+5;const ll inf=1e18;
int n,m,q,w[M];

vector<pair<int,int>>G[M];
inline void cn(ll&x,ll y){x>y&&(x=y);}
ll ds[N][N];
inline void main(){
	scanf("%*d%d%d%*d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int u=1,k;u<=n;u++){
		scanf("%d",&k);
		for(int a,t;k--;){scanf("%d%d",&a,&t);G[a].eb(u,t);}
	}
	memset(ds,0x3f,sizeof ds);
	for(int i=1;i<=n;i++)ds[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto[u,x]:G[i])for(auto[v,y]:G[i])cn(ds[u][v],x+y);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		cn(ds[i][j],ds[i][k]+ds[k][j]);
	for(int i,j;q--;){
		scanf("%d%d",&i,&j);
		ll s=inf;
		for(auto[u,x]:G[i])for(auto[v,y]:G[j])
			cn(s,ds[u][v]+x+y);
		printf("%lld\n",s+w[i]+w[j]);
	}
}

}bool Med;int main(){
#ifdef IO
	freopen("B/subway1.in","r",stdin);
	freopen(".out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	MAOJUN::main();
	return 0;
}