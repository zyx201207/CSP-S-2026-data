#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=505,M=1e3+5;
ll c,n,m,d,q,k,x,y;
ll w[M],a[N],t[N],dp[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i = 1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i = 1;i<=m;i++) dp[i][i]=0;
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&k);
		for(ll j = 1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[i]);
			for(ll d=a[1];d!=a[j];d=a[j+1]){
				dp[d][j]=min(t[d]+t[j],dp[d][j]);
			}
		}
	}
	for(ll k = 1;k<=m;k++){
		for(ll i = 1;i<=m;i++){
			for(ll j = 1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][i]);
			}
		}
	}
	for(ll i = 1;i<=q;i++){
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",w[x]+w[y]+dp[x][y]);
	}
	return 0;
}
