#include<bits/stdc++.h>
using namespace std;

long long n,m,arr[500010],ans=-1e18,dp[10000][10000]; 

int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%lld%lld",&n,&m);

	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}

	sort(arr,arr+n);

	for(int i=n-1;i>0;i--){
		for(int j=0;j<=i;j++){
			dp[i][j]=arr[i]-arr[j];
		}
	}
	
	for(int i=n-1;i>0;i--){
		long long sum=0;
		long long ans1=0;
		for(int j=0;j<=i;j++){
			if(sum+dp[i][j]<=m){
				sum+=dp[i][j];
				ans1++;
			}
		}
		ans=max(ans,ans1);
	}

	printf("%lld",ans);

	return 0;
}
