#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500086], dp[500086], bdk[500086],ddp[500086],cnt,ans;
int main(){
      freopen("crystal3.in","r",stdin);
      freopen("crystal3.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    dp[2] = 1e24;
    for (int i = 1; i < n; i++){
        bdk[i] = 1e24;
        for (int j = 0; j <= n; j++){
            if (i != j && a[i] < a[j]) bdk[i] = min(bdk[i], a[j]-a[i]);
            else continue;
        }
        dp[2]=min(dp[2],bdk[i]);
    }
    for (int i = 3; i <= n; i++){
		ans = 0;
		for (int j = 1; j < i; j++)
			for (int k = i-j; k >= 1; k--)
                ans += bdk[k];
        dp[i] = ans;
	}
	int kksk = 1;
	for (int i = 2; i <= n; i++){
		if (dp[i] <=m){
			ddp[kksk] = dp[i];
			kksk++;
		}
	}
	sort (ddp+1, ddp+kksk+1);
	cout << ddp[kksk]-1;
    return 0;
}

