//GZ-J00546 遵义周林学校 杨莒粞
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[20005],dp[15002][15002] = {0};
int main ()  {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ll n,m,sum = 0,k = 0;
    bool d = false;
    cin >> n >> m;
    for (ll i = 1;i <= n;i++)
      cin >> a[i];
    for (ll i = 1;i <= n;i++)
      dp[1][i] = a[i];
    for (ll i = 2;i <= m;) {
    	for (ll j = 1;j <= n;j++) {
    		for (ll g = 1;g < j;g++) {
    			if (d) dp[i][j] = max (dp[i - k][g] & dp[k][j],dp[i][j]);
    			else dp[i][j] = max (dp[i / 2][g] & dp[i / 2][j],dp[i][j]);
			}
		}
		if (i == m) break;
		if (i * 2 > m) {
			k = i;
			while(i + k > m)
				k = k / 2;
			d = true;
			i += k;
		} else
		  i *= 2;
	}
	for (ll i =1;i <= n;i++)
	  sum = max (dp[m][i],sum);
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
