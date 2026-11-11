#include <bits/stdc++.h>
using namespace std;

#define int long long
#define re register 

const int inf = 0x3f3f3f3f3f3f3f3f;
int _,t,n,d,a[2000001],dp[10001][10001];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> _ >> t;
	while (t--){
		cin >> n >> d;
		int ans = 0;
		for (re int i = 1;i <= n;++i){
			cin >> a[i];
		}
		for (re int l = 1;l + 2 <= n;++l){
			memset(dp,0,sizeof dp);
			dp[l][0] = 1;
			for (re int r = 2;r <= n;++r){
				for (re int i = r - 1;i >= 1;--i){
					for (re int j = 1;j <= r - l;++j){
						if (a[r] - a[i] > d){
							break;
						}
						dp[r][j] += dp[i][j - 1]; 
					}
				}
				for (int i = 1;i <= r - l;++i){
					if (dp[r][i]){
						if (dp[r][i] == 2){
							++ans;
						}
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	} 
	return 0;
} 
//24pts，希望4道题凑起来上天能够赏我个三等奖吧... 
