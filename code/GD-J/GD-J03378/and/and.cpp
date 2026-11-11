#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],dp[200010];
int main() {
	ios::sync_with_stdio();cin.tie();cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	memset(dp,2147483647,sizeof(dp));
	for (int i=1;i<=n;i++) {
		for (int j=m;j>=1;j--) {
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout << dp[m];
	return 0;
}
