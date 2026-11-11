#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
pair<long long,long long> station[500005][25];//1line,2time
long long number[500005]={0};
long long dp[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for (long long i=1;i<=n;i++){
		long long kk;long long temsta,temtime;
		scanf("%lld",&kk);
		for (long long j=1;j<=kk;j++){
			scanf("%lld%lld",&temsta,&temtime);
			number[temsta]++;
			station[temsta][number[temsta]]=make_pair(i,temtime);
		}
	}
	
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++){
			if (i!=j)dp[i][j]=1e18;
		}
	}
//	for (int i=1;i<=m;i++){
//		printf("Sta:%d\n",i);
//		printf("Num:%d\n",number[i]);
//		for (int j=1;j<=number[i];j++){
//			printf("Line:%d   Time:%d  \n",station[i][j].first,station[i][j].second);
//		}
//	}
	for (long long i=1;i<=m;i++){
		long long tem=number[i];
		for (long long j=1;j<=tem;j++){
			for (long long k=1;k<=tem;k++){
				if (j==k)continue;
				long long from=station[i][j].first;
				long long to=station[i][k].first;
				long long value=station[i][j].second+station[i][k].second;
				dp[from][to]=min(dp[from][to],value);
				dp[to][from]=min(dp[to][from],value);
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			printf("i:%d,j:%d,dp:%d\n",i,j,dp[i][j]);
//		}
//	}
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
				dp[j][i]=dp[i][j];
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			printf("i:%d,j:%d,dp:%d\n",i,j,dp[i][j]);
//		}
//	}
	long long x,y;
	for(long long i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		if (x==y)printf("0\n");
		long long res=1e18;
		for (long long j=1;j<=number[x];j++){
			for (long long k=1;k<=number[y];k++){
				long long beginline=station[x][j].first;
				long long destline=station[y][k].first;
				res=min(res,dp[beginline][destline]+station[x][j].second+station[y][k].second);
			}
		}
		printf("%lld\n",res+w[x]+w[y]);
	}
}
