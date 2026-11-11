#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[200005],a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=100005){
		cout<<a[1];
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
		dp[1]=max(dp[1],a[i]);
	}
	cout<<dp[m];
	return 0;
}
