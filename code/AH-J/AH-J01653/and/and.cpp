#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],dp[200005];
bool vis[200005];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	dp[0]=pow(2,30);
	for(int i=1; i<=k; i++) {
		int mx=-1,lst=-1;
		for(int j=1; j<=n; j++) {
			if(vis[j]) continue;
			int o1,o2,op;
			o1=dp[i-1];
			o2=a[j];
			op=(o1&o2);
			if(op>mx) {
				mx=op;
				lst=j;
			}
		}
		vis[lst]=1;
		dp[i]=mx;
	}
	cout << dp[k];
	return 0;
}
