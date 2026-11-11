#include<bits/stdc++.h>
using namespace std;

long long ans;
long long n,m;
long long a[500100];
long long sum[500100];
long long dp[18][7000000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=10000){
		for(int i=1;i<=n;i++){
			int s=0;
			for(int j=i+1;j<=n;j++){
				s=s+(a[j]-a[j-1])*(j-i);
				if(s<=m)  ans=max(ans,1LL*(j-i+1)); 
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=n;i>=1;i--){
		if(m>=sum[i]){
			printf("%d",i);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
