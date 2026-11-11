#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n,m;
ll a[N],dp[N],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		dp[0] = a[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp[j] = max(dp[j],(dp[j - 1] & a[i]));
	cout<<dp[m]<<'\n';
	return 0;
}
