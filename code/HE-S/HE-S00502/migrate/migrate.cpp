#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6;
ll x[maxn],dp[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin >> c >> t;
	while(t--){
		ll n,d;
		cin >> n >> d;
		fill(x,x+n,0);
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		sort(x,x+1+n);
		for(int i = 2; i <= n; i++){
			if(x[i]-x[i-1]<=d){
				dp[i] = dp[i-1]+1;
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(dp[j] - dp[i] == d+1) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
