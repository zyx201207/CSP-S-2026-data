#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
long long a[N],dp[N],n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dp[1]=a[1];
	for(int i = 2;i <= n;i++){
		dp[i]=dp[i-1]&a[i];
	}
	for(int i = m;i <= n;i++){
		dp[i]=max(dp[i-1],dp[i-m]&a[i]);
	}
	cout << dp[n];
	return 0;
}
