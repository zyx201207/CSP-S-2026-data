#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],cost[N],dp[N],ans;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[i]=1+dp[i-1];
		if(a[i]==a[i-1]){
			cost[i]=cost[i-1];
			ans=max(dp[i],ans);
			continue;
		}
		cost[i]=cost[i-1]+dp[i-1]*(a[i]-a[i-1]);
		if(cost[i]>m){
			for(int j=i-dp[i-1];j<=i-1;j++){
				cost[i]-=(a[i]-a[j]);
				dp[i]--;
				if(cost[i]<=m)break;
			}
		}
		ans=max(dp[i],ans);
	}

	printf("%lld",ans);
	return 0;
}
