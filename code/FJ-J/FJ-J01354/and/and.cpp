#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
ll dp[N][N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		ll ma=-1;
		for(int i=1;i<=n;i++)ma=max(ma,a[i]);
		printf("%lld",ma);
	}
	if(m==2){
		ll ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
		printf("%lld",ma);
		
	}
	if(m==n){
		ll sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		printf("%lld",sum);
	}
	else{
	ll maxn=-1;
	for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
	for(int i=1;i<=n;i++)dp[1][i]=maxn;
	maxn=-1;
	for(int i=2;i<=m;i++){
		for(int j=1;i<=n;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]&a[j]);
			maxn=max(maxn,dp[i][j]);
		}
	}-
	printf("%lld",maxn);
	}
	return 0;
}
