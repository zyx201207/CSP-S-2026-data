#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    int m,n,a[200009] = {},a1[2001][40] = {},a2[2001] = {};
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        int fl = 0,b = a[i];
        while(b != 0){
            a1[i][++fl] = b % 2;
            b /= 2;
        }
        a2[i] = fl;
    }
    int dp[200009] = {},dp1[200009] = {};
    for(int k = 1;k <= n;k++){
		dp1[1] = a[k];
        for(int i = 1;i <= m;i++){
			if(i == k){
				continue;
			}
            for(int j = n;j >= m - i;j--){
				int h = 0,h1 = 1;
                for(int g = 1;g <= min(a2[k],a2[j]);g++){
                    if(a1[k][g] == a1[j][g] && a1[k][g] == 1){
                        for(int g1 = 1;g1 <= g;g1++){
                            h1 *= 2;
                        }
                        h += h1;
                        h1 = 1;
                    }
                }
                dp1[j] = max(dp1[j],dp1[j - 1] + h);
            }
        }
        dp[n] = max(dp[n],dp1[n]);
    }
    cout << dp1[n];
    return 0;
}
