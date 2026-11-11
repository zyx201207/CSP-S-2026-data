#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int c,n,m,d,q,k[N];
ll w[N],a[N][N],t[N][N];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[a[i][j]][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ll dp[N];
		for(int j=1;j<=n;j++)
			for(int l=x;l<=k[j];l++)
				dp[a[j][l]]=min(dp[a[j-1][l]],dp[a[j][l]]+t[a[j][l]][j]);
		printf("%lld\n",dp[y]+w[x]+w[y]);
	}
	return 0;
}
