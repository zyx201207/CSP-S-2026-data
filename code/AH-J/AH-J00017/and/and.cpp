#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 2e5+5;
int n,m,a[M];
int dp[M][M];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int t0=clock();

    cin >> n >> m;
    for(int i=1 ; i<=n ; ++i)
    {
        cin >> a[i];
        dp[0][i]=INT_MAX;
        dp[i][0]=INT_MAX;
    }

    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=m&&j<=i ; ++j)
        {
            for(int k=j+1 ; k<=m&&k<=i ; ++k)
            {
                dp[i][j] = max(dp[i][j] , dp[i][j-1]&a[k]);
            }
        }
    }
    cout << dp[n][m];

    //cout << "\ntimeuse:" << clock()-t0 << "ms";
    cout << endl;
    return 0;
}
