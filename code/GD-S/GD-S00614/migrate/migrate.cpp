#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5005;
int n,dis[N][N],cnt[N][N];
ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;scanf("%d %d",&c,&T);
	while(T--){
		scanf("%d %lld",&n,&d);int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=(i==j?0:1e9),cnt[i][j]=0;
		for(int i=1;i<=n;++i) scanf("%lld",x+i);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(x[j]-x[i]<=d) dis[i][j]=cnt[i][j]=1;
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j) if(i^k&&j^k){
					int res=dis[i][k]+dis[k][j];
					if(res<dis[i][j]) dis[i][j]=res,cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(res==dis[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				ans+=(cnt[i][j]==2);
		printf("%d\n",ans);
	}
	return 0;
}
