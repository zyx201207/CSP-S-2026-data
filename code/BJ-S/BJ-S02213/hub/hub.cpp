#include <bits/stdc++.h>
using namespace std;
long long c , t , dp[1000010] , sum[1000010] , fa[1000010] , n , k;
vector<int> e[1000010];
void dfs1(int id)
{
    for(int i : e[id])
    {
        if(fa[id] != i)
        {
            fa[i] = id;
            dfs1(i);
            sum[id] += sum[i];
            dp[id] += dp[i] + sum[i]; 
        }
    }
    sum[id]++;
}
void dfs2(int id)
{
    for(int i : e[id])
    {
        if(fa[id] != i)
        {
            dp[i] = dp[id] + n - sum[i] * 2;
            dfs2(i);
        }
    }
}
int mark[1000010];
int dfs(int id)
{
    int cnt = 0;
    for(int i : e[id])
    {
        if(mark[i])
        {
            cnt++;
            mark[i] = 0;
            cnt += dfs(i);
        }
    }
    return cnt;
}
bool check(long long mid)
{
    long long cnt = 0 , cnt1 = 0 , cnt2 = 0 , cnt3;
    for(int i = 1;i <= n;i++)
    {
        if(dp[i] <= mid) mark[i] = 1 , cnt1++;
        else mark[i] = 0;
    }
    if(cnt1 < k) return 0;
    for(int i = 1;i <= n;i++)
    {
        if(mark[i] == 1)
        {
            cnt++;
            int t = dfs(i);
            if(t > cnt2) cnt3 = cnt2 , cnt2 = t;
            else cnt3 = max(cnt3 , t); 
        }
    }
    return cnt <= 2 || cnt2 + cnt3 >= k;
}
int main()
{
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    cin >> c >> t;
    while(t--)
    {
        memset(fa , 0 , sizeof(fa));
        memset(sum , 0 , sizeof(sum));
        memset(dp , 0 , sizeof(dp));
        cin >> n >> k;
        for(int i = 1;i <= n;i++) e[i].clear();
        for(int i = 1;i < n;i++)
        {
            int u , v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs1(1);
        dfs2(1);
        long long maxn = -1e18;
        for(int i = 1;i <= n;i++) maxn = max(maxn , dp[i]);
        long long l = 0 , r = maxn , ans = 1e18;
        while(l <= r)
        {
            long long mid = (l + r) >> 1;
            if(check(mid))
            {
                ans = min(ans , mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}