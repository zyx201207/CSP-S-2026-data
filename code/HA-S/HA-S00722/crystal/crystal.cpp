#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int dp[99999999];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i+1]-a[i];j--){
			dp[j]=max(dp[j],dp[j-a[i+1]+a[i]]+1);
		}
	}
	cout<<dp[m];
	return 0;
}

