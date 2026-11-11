#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long dif[500005];
long long dp[500005];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++) dif[i] = a[i+1] - a[i];
//	for (int i=1;i<=n;i++) cout<<dif[i]<<' ';
//	cout<<'\n';
	int res = 0;
	for (int i=1;i<=n;i++){
		for (int j=i;j>=1;j--){
			dp[j] = j*dif[i-1] + dp[j-1];
			if (dp[j] <= m) res = max(j,res);
		}

	}
	cout<<res+1;
}
