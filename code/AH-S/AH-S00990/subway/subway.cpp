#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5,N=505,D=25;
int c,n,m,dd,q;
ll d[N][N],W[M];
int id[M][D],w[M][D],dg[M];
int tmp[D],tw[D];
void cmn(ll &x,ll y){y<x&&(x=y);}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&dd,&q);
	for(int i=1;i<=m;++i) scanf("%lld",&W[i]);
	for(int i=1;i<=n;++i){
		int l;
		scanf("%d",&l);
		for(int j=1;j<=l;++j){
			int x,y;
			scanf("%d%d",&x,&y);
			id[x][++dg[x]]=i,w[x][dg[x]]=y;
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;++i) d[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=dg[i];++j) tmp[j]=id[i][j],tw[j]=w[i][j];
		for(int j=1;j<=dg[i];++j){
			for(int k=1;k<=dg[i];++k) cmn(d[tmp[j]][tmp[k]],tw[j]+tw[k]);
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) cmn(d[i][j],d[i][k]+d[k][j]);
		}
	}
	for(int i=1,x,y;i<=q;++i){
		scanf("%d%d",&x,&y);
		ll now=1e18,ans=W[x]+W[y];
		for(int j=1;j<=dg[x];++j){
			for(int k=1;k<=dg[y];++k) cmn(now,w[x][j]+w[y][k]+d[id[x][j]][id[y][k]]);
		}
		printf("%lld\n",ans+now);
	}
	return 0;
} 
