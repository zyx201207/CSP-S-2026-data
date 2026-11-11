#include<bits/stdc++.h>
using namespace std;
const int M=100005;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int dp[M],a[M];
	for(int i=1;i<=n;i++)cin>>a[i],dp[i]=a[i];
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]&dp[i]);
	}
	cout<<dp[n];
	return 0;
}
