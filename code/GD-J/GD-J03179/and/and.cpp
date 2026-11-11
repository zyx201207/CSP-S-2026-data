#include<bits/stdc++.h>
using namespace std;
vector<int>dp[200001];
int a[200001],n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dp[i].push_back(0);
		dp[i].push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=min(m,i);j++){
			dp[i].push_back(max(dp[i-1][j],dp[i-1][j-1]&a[i]));
		}
	}
	int ans=-10086;
	for(int i=m;i<=n;i++){
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
