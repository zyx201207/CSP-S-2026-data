#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m;
long long x[N], dp[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
	}
	dp[0] = (1<<30) - 1;
	for(int i=1;i<=n;i++) {
		for(int j=m;j>=1;j--) {
			dp[j] = max(dp[j-1] & x[i] , dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
