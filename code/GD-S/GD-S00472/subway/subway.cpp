#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
const long long inf=1000000000000000000ll,D=22;
int c,n,m,d,q;
long long w[M];
int cnt[M],id[M][D];
long long tim[M][D];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int a,tm;
			scanf("%d%d",&a,&tm);
			id[a][++cnt[a]]=i,tim[a][cnt[a]]=tm;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=cnt[i];++j)
			for(int k=1;k<=cnt[i];++k){
				if(j==k)continue;
				dis[id[i][j]][id[i][k]]=min(dis[id[i][j]][id[i][k]],tim[i][j]+tim[i][k]);
			}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){ 
		int x,y;
		long long ans=inf;
		scanf("%d%d",&x,&y);
		for(int j=1;j<=cnt[x];++j)
			for(int k=1;k<=cnt[y];++k){
				ans=min(ans,w[x]+w[y]+tim[x][j]+tim[y][k]+dis[id[x][j]][id[y][k]]);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
