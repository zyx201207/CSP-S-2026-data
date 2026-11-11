#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010],ai,aj;
bool f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		long long maxx=-1;
		for(int i=1;i<=n;i++)
			maxx=max(a[i],maxx);
		printf("%lld",maxx);
		return 0;
	}
	else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++)  ans=(ans & a[i]);
		printf("%lld ",ans);
		return 0;
	}
	else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i] & a[j])>dp[2]){
					dp[2]=(a[i] & a[j]);
					ai=i;
					aj=j;
				}
				
			}
		}
		f[ai]=1;
		f[aj]=1;
		for(int i=3;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(f[j]!=1){
					if((a[j] & dp[i-1])>dp[i]){
						dp[i]=(a[j] & dp[i-1]);
						ai=j;
					}
				}
			}
			f[ai]=1;
		}
	}
	printf("%lld\n",dp[m]);
	return 0;
}
