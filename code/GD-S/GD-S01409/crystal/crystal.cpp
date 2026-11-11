#include<bits/stdc++.h>
using namespace std;
long long dp[500005],a[100005];//dp[i]表示以a[i]为基准的最大数量 
long long labs(long long x){
	if(x<0){
		return -x;
	}
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,m1,ans=-1,mx;
	scanf("%lld%lld",&n,&m);
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	dp[0]=a[0]=0;
	for( ;r<=n;){
		long long s1=dp[r-1]*labs(a[r]-a[r-1]);//将r往后滑动一位的代价
		long long s2=labs(a[r]-a[l]);//将l往前滑动一位的代价 
		if(m1<s1&&m1<s2){
			dp[r]=1,m1=m,l=r;
			ans=max(ans,dp[r]);
			r++;
		}
		else if(s1<s2||l<=1){
			dp[r]=dp[r-1]+1,m1-=s1;
			ans=max(ans,dp[r]);
			r++;
		}
		else{
			dp[r-1]++,m1-=s2,l--;
			ans=max(ans,dp[r-1]);
		}
	} 
	printf("%lld",ans);
	return 0;
}
/*

5 8 
-3 -1 2 2 7
ans:-3 -1 2 2


*/
