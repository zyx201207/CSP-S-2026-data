#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			if(dp[j-1]==0){
				dp[j]=max(dp[j],a[i]);
			}else dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	printf("%lld",dp[m]);
	return 0;
} 
