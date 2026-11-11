#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int a[200005], dp[2005][2005];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    if(m == 1){
        int maxn = 0;
        for(int i = 1; i <= n; ++i){
            maxn = max(a[i], maxn);
        }
        cout << maxn << endl;
    }
    if(m == 2){
    int maxn = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                maxn = max(maxn, a[i]&a[j]);
            }
        }
        cout << maxn << endl;
    }
    if(m != 1 && m != 2){
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i){
            for(int j = m; j >= 1; --j){
                dp[i][j] = max(dp[i-1][j], (dp[i-1][j-1]&a[i])+((dp[i-1][j-1] == 0)*a[i]));
            }
        }
        cout << dp[n][1] << endl;
    }
    return 0;
}