#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[300],mn[300],a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,C;
	cin >> C >> T;
	while(T--){
		int n,d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		int ans = 0;
		for (int st = 1;st <= n;st++){
			for (int i = st;i <= n;i++)
				dp[i] = 0,mn[i] = 1e18;
			dp[st] = 1,mn[st] = 0;
			for (int i = st; i <= n;i++){
				if(dp[i] == 2) ans++;
				for (int r = st + 1;r <= n;r++){
					if (a[r] - a[i] > d) break;
					if (mn[i] + 1 < mn[r])
						mn[r] = mn[i] + 1,dp[r] = dp[i];
					else if (mn[i] + 1 == mn[r])
						dp[r] += dp[i];
				}
			}
			//printf("%d : ",st);
			//for (int i = st;i <= n;i++)
			//	printf("%lld ",dp[i]);
			//printf("\n");
		}
		printf("%lld\n",ans);
	}
	return 0;
}
