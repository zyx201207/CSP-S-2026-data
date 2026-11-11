#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=505,Maxm=500005;
const ll INF=1e18;
int c,n,m,d,k,q,aa;
ll G[Maxn][Maxn],w[Maxm],ans,ti[Maxm],tt;
int head[Maxm],pre[Maxm],val[Maxm],len;
void ins(int u,int v,ll ttt){pre[++len]=head[u];head[u]=len;val[len]=v;ti[len]=ttt;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",w+i);
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		for(int j=0;j<k;++j){scanf("%d%lld",&aa,&tt);ins(aa,i,tt);}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
		if (i==j) G[i][j]=0;
		else G[i][j]=INF;
	}
	for(int i=1;i<=m;++i) for(int j=head[i];j;j=pre[j]) for(int k=head[i];k;k=pre[k]){
		int u=val[j],v=val[k];ll cur=ti[j]+ti[k];
		if (G[u][v]>cur) G[u][v]=cur;
	}
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if (G[i][k]+G[k][j]<G[i][j]) G[i][j]=G[i][k]+G[k][j];
	while(q--){
		ans=INF;int u,v;scanf("%d%d",&u,&v);
		for(int i=head[u];i;i=pre[i]) for(int j=head[v];j;j=pre[j]){
			ll cur=ti[i]+ti[j]+G[val[i]][val[j]];
			if (cur<ans) ans=cur;
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
