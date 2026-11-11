#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[200010], dp[200010];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	dp[0] = (ll)pow(2, 32) - 1;
	ll cnt = 0; 
	for(int i = 1; i <= n; i ++){
		for(int j = i; j >= 1; j --){
			dp[j] = max(dp[j], (dp[j - 1] & a[i]));
		}
	}
	
	cout << dp[m];
	
	return 0;
}
