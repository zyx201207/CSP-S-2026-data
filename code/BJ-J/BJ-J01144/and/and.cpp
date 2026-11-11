#include <bits/stdc++.h>
using namespace std;

long long a[10000010];
long long dp[10000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	dp[0]=a[0];
	for (int i=1;i<m;i++){
		dp[i]=a[i];
	}
	for (int i=m;i<n;i++){
		dp[i]=max(dp[i-1],(a[i]&a[i+1]));
	}
	cout << dp[n-1];
	return 0;
}
