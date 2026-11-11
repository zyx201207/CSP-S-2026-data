#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (long long i = 1;i<=n;i++){
		cin>>a[i];
	}dp[0] = INT_MAX;
	for (long long i = 1;i<=n;i++){
		for (long long j = m;j>=1;j--){
			dp[j] = max(dp[j],dp[j-1]&a[i]);
		}
	}cout<<dp[m];
	return 0;
}
