#include <bits/stdc++.h>
using namespace std;
#define N 2000006
#define inf 1000000000
#define ll long long
int c,t,n,dp[N];
ll d,a[N],f[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;++i) cin >> a[i];
		for(int i = 1;i <= n;++i){
			for(int j = i+1;j <= n;++j) f[j] = 0,dp[j] = inf;
			f[i] = 1,dp[i] = 0;
			for(int j = i,k;j <= n;++j){
				if(f[j] > 2 && n >= 1000) continue;
				for(int k = j+1;k <= n;++k){
					if(a[k] - a[j] > d) break;
					if(dp[k] > dp[j]+1) dp[k] = dp[j]+1,f[k] = f[j];
					else if(dp[k] == dp[j]+1) f[k] += f[j];
				}
			}
			for(int j = i+1;j <= n;++j) if(f[j] == 2) ++ans;
		}
		cout << ans << '\n';
	} 
	return 0;
}
