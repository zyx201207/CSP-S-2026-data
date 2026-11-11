#include <bits/stdc++.h>
using namespace std;
long long a[1000002];
long long dp[1000002];
long long cnt[1000002];
int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 1;i<= n;i++)
    {
        dp[ans] = a[ans];
        for(int j = ans+1;j <= n;j++)
        {
            for(int k = ans;k < j;k++)
            {
                if(dp[k] == a[j])
                {
                    for(int b = ans; b < j;b++) dp[b] = 0;
                    dp[j] = a[j];
                    break;
                }
                dp[j] = a[j];
            }

        }
        for(int j = ans; j<=n;j++)
        {
            for(int k = 1; k<= n;k++)
            {
                if(dp[j] == a[k])
                {
                    cnt[a[k]] ++;
                    break;
                }
            }

        }
        cout << endl;
        ans++;
    }
    for(int i = 1;i <= m;i++)
    {
        cout<< cnt[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
