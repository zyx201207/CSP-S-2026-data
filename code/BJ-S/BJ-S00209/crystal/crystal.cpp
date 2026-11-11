#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500005];
int dp[200][10005][205];
int ans;

int b(){
    int d = a[2]-a[1];
    for (int i=2; i<n; i++){
        if (a[i+1]-a[i] != d){
            return -1;
        }
    }
    return abs(d);
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    int in = INT_MAX, ax = INT_MIN;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        in = min(in, a[i]);
        ax = max(ax, a[i]);
    }
    if (in < 0){
        for (int i=1; i<=n; i++){
            a[i] -= in;
        }
        ax -= in;
        in -= in;
    }
    if (n == 1){
        cout<<1<<endl;
        return 0;
    }
    if (b() != -1){
        int d = b();
        int x = 1;
        while (m >= x*d){
            ans++;
            m -= x*d;
            x++;
        }
        ans++;
        ans = min(ans, n);
        cout<<ans<<endl;
        return 0;
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=m; j++){
            for (int k=in; k<=ax; k++){
                dp[i][j][k] = dp[i-1][j][k];
                int x = k-a[i];
                if (x >= 0){
                    if (j >= x){
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-x][k]+1);
                    }
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
