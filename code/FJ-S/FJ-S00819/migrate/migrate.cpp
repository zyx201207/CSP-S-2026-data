#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int c,t,n,dp[N][N],f[N][N];
long long d,x[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		    cin >> x[i];
		memset(dp,0,sizeof(dp));
		memset(f,0x3f,sizeof(f));
	    for (int i = 1;i <= n;i++)
	        dp[i][1] = 1,f[i][1] = 0;
		for (int l = 2;l <= n;l++){
		    for (int i = n - l + 1;i >= 1;i--){
		    	long long res = 0;
		    	for (int j = i + 1;j <= i + l - 1;j++){
		    		if (x[j] - x[i] <= d){
		    			if (f[j][i + l - j] + 1 < f[i][l]){
		    				f[i][l] = f[j][i + l - j] + 1;
		    				res = dp[j][i + l - j];
						}
						if (f[j][i + l - j] + 1 == f[i][l])
						    res += dp[j][i + l - j];
					}
				}
				dp[i][l] = res;
			}
		}
		for (int i = 1;i <= n;i++)
	        for (int j = 1;i + j - 1 <= n;j++)
	            if (dp[i][j] == 2) ans++;
	    cout << ans << endl;
	}
}
