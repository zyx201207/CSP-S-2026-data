#include <bits/stdc++.h>
using namespace std;

long long int dp[5010][10010];

vector<long long int> nums;

int main()
{
    freopen("and2.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long int n, m;
    cin >> n >> m;

    int sss = -1;
    nums.push_back(-128);
    for (int i = 0;i < n;i++){
        long long int x;
        cin >> x;
        if (sss == -1) sss = x;
        else sss &= x;
        nums.push_back(x);
    }

    if (m == n)
    {

        cout << sss;
    }


    for (int i = 1;i <= m;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (i == 1)
            {
                long long int maxN = -128;

                for (int k = 1;k <= j;k++) maxN = max(maxN, nums[k]);
                dp[i][j] = maxN;

            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] & nums[j]);

            }
        }
    }
    cout << dp[m][n];
    return 0;
}
