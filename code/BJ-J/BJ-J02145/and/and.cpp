#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n, m, a[N], ans = -1e7;
bool vis[N];
void dfs(int num,int cnt)//num:下标，cnt:选几个
{
    if(cnt == m)
    {
        int t = -1;
        for(int i=1;i<=num;i++)
        {
            if(vis[i])
            {
                if(t == -1) t = a[i];
                t = (t & a[i]);
            }
        }
        ans = max(ans, t);
        return ;
    }
    if(num == n) return ;
    if(cnt < m)
    {
        vis[num+1] = 1;
        dfs(num+1,cnt+1);
    }
    vis[num+1] = 0;
    dfs(num+1,cnt);
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(m == n)
    {
        ans = a[1];
        for(int i=2;i<=n;i++) ans &= a[i];
    }

    else if(m == 1)
    {
        for(int i=1;i<=n;i++) ans = max(ans,a[i]);
    }

    else if(m == 2)
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i != j) ans = max(ans,(a[i]&a[j]));
    }

    else if(m == n-1)
    {
        for(int i=1;i<=n;i++)
        {
            int cnt = -1;
            for(int j=1;j<=n;j++)
            {
                if(j == i) continue;
                if(cnt == -1) cnt = a[i];
                cnt &= a[i];
            }
            ans = max(ans,cnt);
        }
    }

    else dfs(0,0);

    cout<<ans;
    return 0;
}
