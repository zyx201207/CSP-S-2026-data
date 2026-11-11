#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	vector<ll> a(n+1);
	vector<vector<ll>> dp(n+1,vector<ll>(m+1));
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a.rbegin(),a.rend());
	dp[1][1] = a[1];
	if(m == 1){
	    ll ans = -1;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans,(a[i] & a[j]));
			}
		} 
	}
	else{
		for(int i = 2;i <= n;i++){
		    for(int j = 2;j <= m;j++){
			    dp[i][j] = max(dp[i-1][j],dp[i-1][j-1] & a[i]);
		    }
	    }
	    cout<< dp[n][m];
	} 
}
