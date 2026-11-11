#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int  a[N];
int dp[N];
int n,m;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
		for(int j=1;j<=m;j++){
			dp[i]=max(dp[i],(dp[i]&a[i]));
		}
	}
	cout<<dp[n];
	return 0;
}

