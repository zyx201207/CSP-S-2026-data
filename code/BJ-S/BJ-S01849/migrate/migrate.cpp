#include<bits/stdc++.h>
#define int long long
using namespace std;
int c , t , n , d , x[2000005] , dp[2000005] , fp[2000005] , pre[2000005] , nxt[2000005] , tong[2000005] , l , r , mid , anss , ans , ql , qr;
signed main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> x[i];
        }
        for(int i = 1 ; i <= n ; i++)
        {
            l = 1;
            anss = r = i;
            while(l <= r)
            {
                mid = (l + r) / 2;
                if(x[i] - x[mid] <= d)
                {
                    anss = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            pre[i] = anss;
            l = anss = i;
            r = n;
            while(l <= r)
            {
                mid = (l + r) / 2;
                if(x[mid] - x[i] <= d)
                {
                    anss = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            nxt[i] = anss;
        }
        for(int i = 0 ; i <= n + 1 ; i++)
        {
            tong[i] = 0;
            dp[i] = fp[i] = 0;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            dp[i]++;
            if(pre[nxt[i]] == i)
            {
                dp[nxt[i]] += dp[i];
            }
            else
            {
                if(nxt[i] != i)
                {
                    dp[nxt[i]]++;
                }
            }
        }
        for(int i = n ; i >= 1 ; i--)
        {
            fp[i]++;
            if(nxt[pre[i]] == i)
            {
                fp[pre[i]] += fp[i];
            }
            else
            {
                if(pre[i] != i)
                {
                    fp[pre[i]]++;
                }
            }
        }
        ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(pre[i] + 1 < i)
            {
                if(nxt[pre[i] + 1] == i)
                {
                    ans += fp[i] * tong[pre[i] + 1];
                }
                else
                {
                    ans += tong[pre[i] + 1];
                }
            }
            if(pre[nxt[i] - 1] == i)
            {
                tong[nxt[i]] += dp[i];
            }
            else
            {
                tong[nxt[i]]++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
3:13: 调完 n^2 发现可以直接优化到 n log 然后一直过不了大样例3，对排立大功，WC 应该稳了
这题花了 2 个多小时，没什么时间拼 T4 暴力了 www
在 2:50 的时候有过犹豫，是否要放弃调试。
哪有小孩天天哭，哪有赌徒天天输。
*/
