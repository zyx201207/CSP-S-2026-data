#include <bits/stdc++.h>
using namespace std;
typedef long long intt;

const intt MAXN = 5000 + 5;
intt c,t,n,d;
intt a[MAXN],r[MAXN],dp[MAXN][MAXN];
intt cnt[MAXN][MAXN];


void solve() {
	scanf("%lld%lld",&n,&d);
	memset(cnt,0,sizeof(cnt));
	memset(dp,0x3f3f,sizeof(dp));
	for(intt i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for(intt i = 1;i <= n;i++) {
		for(intt j = i + 1;j <= n;j++) {
			if(a[i] + d < a[j]) break;
			dp[i][j] = 1;
		}
	}
		
	for(intt k = 1;k <= n;k++)
		for(intt i = 1;i <= n;i++)
			for(intt j = i + 1;j <= n;j++) 
				if(dp[i][k] + dp[k][j] < dp[i][j]) {
					cnt[i][j] = 1,dp[i][j] = dp[i][k] + dp[k][j];
				} else if(dp[i][k] + dp[k][j] == dp[i][j]) cnt[i][j]++;
				
			
	intt ans = 0;
	for(intt i = 1;i <= n;i++) {
		for(intt j = i + 1;j <= n;j++) if(cnt[i][j] == 2) ans++;
		// for(intt j = 1;j <= n;j++) cout << cnt[i][j] << " ";
		// cout << "\n";
	}
		
	printf("%lld\n",ans);
}

int main() {
	
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
} 
