#include <bits/stdc++.h>
using namespace std;
int dp[200010], ans, n, m;
int a[200010];
void dfs(int step, int sum, int last)
{
    if(sum <= ans)return;
    if(step > m)
    {
        ans = max(ans, sum);
        return ;
    }
    for(int i = last + 1;i <= n;i++)
    {
        dfs(step + 1, sum & a[i], i);
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    dfs(1, 2147483647, 0);
    cout<<ans;
    return 0;
}