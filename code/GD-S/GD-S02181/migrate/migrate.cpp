#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL const MAXN = 5010;

LL t, n, d;
LL a[MAXN];
LL dp[MAXN][MAXN];//从i到j的方案数 

void Solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	LL ans = 0; 
	memset(dp, 0, sizeof(dp));
	
	for(int i = 1; i <= n; i++)dp[i][i] = 1;
		
	LL ss = 0;
	for(int tt = 1; tt <= n; tt++){
		while(a[tt] - a[ss] > d)ss++;
		for(int i = 1; i < tt; i++){
			for(int j = max(i, int(ss)); j < tt; j++){
				dp[i][tt] += dp[i][j];
			}
			if(dp[i][tt] == 2){ans++;//从i到tt（最后一步是j）,行走方案数量为2
			cout << i << " " << tt << '\n';}
			cout << ss << " " << tt << ": " << dp[i][tt] << '\n';
		}
	}
	cout << ans << '\n';
}



int main()
{
	cin >> t >> t;
	while(t--)Solve();
	
	return 0;
}
