#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int dp[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[i]=max(dp[i-1],(dp[j] & a[i]));
		}
	}
	cout<<dp[n];
	return 0;
}
