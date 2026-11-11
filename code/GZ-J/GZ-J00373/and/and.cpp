//GZ-J00373  兴义市弘毅中学 梁羽辰
#include<bits/stdc++.h>
using namespace std;
long long m,n,dp[200005],a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max(dp[i-1],dp[i-1]+dp[i-1]&dp[i]);
	}
	for(int i=n;i>=2;i--){
		dp[i]=max(dp[i-1],dp[i-1]+dp[i-1]&dp[i]);
	}
	cout<<dp[n];
	return 0;
} 
