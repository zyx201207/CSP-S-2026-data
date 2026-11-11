#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005],a[500005],t[500005],dp[505][505],n,m,d,q,k,x,y;
int main(){
	//freopen("subway1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&x,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf(" %lld",w+i);
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dp[i][j]=0x3f3f3f3f3f3f3f3fll;
	for(int i=1;i<=n;i++){
		scanf(" %lld",&k);
		for(int j=1;j<=k;j++) scanf(" %lld%lld",a+j,t+j);
		for(int j=1;j<=k;j++) for(int l=j+1;l<=k;l++)
			dp[a[j]][a[l]]=dp[a[l]][a[j]]=t[j]+t[l];
	}
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)
		dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		scanf(" %lld%lld",&x,&y);
		printf("%lld\n",dp[x][y]+w[x]+w[y]);
	}
	return 0;
}//TLE on #ex5,#ex6
