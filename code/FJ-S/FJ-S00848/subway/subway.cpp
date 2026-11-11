#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll c,n,m,d,q;   
void work(){
	ll w[N]={0},k[600]={0},a[600][N]={0},t[600][N]={0},st[N],ed[N];
	bool edge[N][N];
	ll dp[N][N]={1000000000};
	for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			if(j>1){
				edge[a[i][j]][a[i][j-1]]=edge[a[i][j-1]][a[i][j]]=1;
				dp[a[i][j]][a[i][j-1]]=dp[a[i][j-1]][a[i][j]]=t[i][j]+t[i][j-1];
			} 
		 } 
	}
	for(ll i=1;i<=m;i++)
		for(ll j=i;j<=m;j++){
			for(ll k=j;k<=m;k++){
				if(edge[i][j]&&edge[j][k]) dp[i][k]=min(dp[i][k],dp[i][j]+dp[j][k]);
			}
		}
	for(ll i=1;i<=q;i++){
		scanf("%lld%lld",st[i],ed[i]);
		printf("%lld\n",dp[st[i]][ed[i]]);
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&c);
	work();
}