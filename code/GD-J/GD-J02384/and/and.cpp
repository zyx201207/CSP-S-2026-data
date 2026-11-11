#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> dp(200010),odp(200010);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		odp[i]=a[i];
	}
	for(int i = 0;i < m-1;i++){
		for(int j = 0;j < n;j++){
			dp[j]=0;
		}
		for(int j = 0;j < n;j++){
			for(int k = 0;k < j;k++){
				dp[j]=max(dp[j],odp[k]&odp[j]);
			}
		}
		odp=dp;
	}
	int ans=0;
	for(int i = 0;i < n;i++){
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
