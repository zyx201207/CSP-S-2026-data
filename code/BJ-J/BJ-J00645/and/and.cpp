#include<iostream>
using namespace std;
long long a[200010];
long long dp[200010];
int n,k;
long long maxn(long long x,long long y){
	if(x>=y){
		return x;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=k;i++){
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		dp[0]=a[i];
		for(int j=k;j>=1;j--){
			dp[j]=maxn(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[k];
	return 0;
}
