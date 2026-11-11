#include<bits/stdc++.h>
#define ll long long
#define N 500009//¿ª´ó 
#define K 509
#define inf 214748364700000
using namespace std;
ll w[N],dp[K][K];
ll a[N][21],num[N],b[N][21];
ll Min(ll x,ll y){
	if(x<y)return x;
	return y;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway7.in","r",stdin);
//	freopen("ans.out","w",stdout);
	ll c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	ll cnt=0;
	for(ll i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++){
		ll len,x,val;
		cnt++;
		scanf("%lld",&len);
		for(ll j=1;j<=len;j++){
			scanf("%lld%lld",&x,&val);
			num[x]++;
			a[x][num[x]]=cnt,b[x][num[x]]=val;
		} 
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)dp[i][j]=inf;
	for(ll i=1;i<=n;i++)dp[i][i]=0;
	for(ll i=1;i<=m;i++){
		ll len=num[i];
		for(ll j=1;j<=len;j++)
			for(ll k=j+1;k<=len;k++){
				ll x=a[i][j],y=a[i][k],v1=b[i][j],v2=b[i][k];
				if(x>y)swap(x,y);
				dp[x][y]=Min(dp[x][y],v1+v2);
			}
	}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++){
				if(i<=k&&k<=j)dp[i][j]=Min(dp[i][j],dp[i][k]+dp[k][j]);
				if(i<=j&&j<=k)dp[i][j]=Min(dp[i][j],dp[i][k]+dp[j][k]);
				if(k<=i&&i<=j)dp[i][j]=Min(dp[i][j],dp[k][i]+dp[k][j]);
			}
	while(q--){
		ll x,y,ans=0;
		scanf("%lld%lld",&x,&y);
		ans+=w[x]+w[y];
		ll l1=num[x],l2=num[y],sum=inf;
		for(ll i=1;i<=l1;i++)
			for(ll j=1;j<=l2;j++){
				ll s=a[x][i],t=a[y][j];
				ll val=b[x][i]+b[y][j];
				if(s>t)swap(s,t);
				val+=dp[s][t];
				sum=Min(sum,val);
			}
		printf("%lld\n",ans+sum);
	} 
	return 0;
}
