#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--){
		if(j==1) dp[j]=max(dp[j],a[i]);
		else dp[j]=max(dp[j],dp[j-1]&a[i]);
	}
	cout<<dp[m]<<"\n";
	return 0;
}
