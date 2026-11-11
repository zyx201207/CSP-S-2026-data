#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N = 2e5 + 10;
int a[N];
int res[N],vis[N];
int maxn = -0x3f3f3f3f;
void dfs(int cnt)
{
    if(cnt == m)
    {
        int ans = res[0];
        for(int i = 1;i < cnt;i++)
        {
            ans = ans & res[i];
        }
        maxn = max(maxn,ans);
        // for(int i = 0;i < cnt;i++)
        // {
        //     cerr << res[i] << " ";
        // }
        // cerr << endl;
        return;
    }
    for(int i = 0;i < n;i++)
    {
        if(vis[i])return;
        vis[i] = 1;
        res[cnt] = a[i];
        dfs(cnt+1);
        vis[i] = 0;
    }
    return;
}
bool cmp(int a,int b)
{
    return a > b;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //freopen("and.err","w",stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    if(n <= 4000)
    {
        dfs(0);
    }
    else
    {
        sort(a,a+n,cmp);
        int ans = a[0];
        for(int i = 1;i < m;i++)
        {
            ans &= a[i];
        }
        maxn = ans;
    }
    cout << maxn;
    return 0;
}

void CSP_J(int AK)
{
    int RP = 100;
    int Inf = 0x3f3f3f3f;
    RP+=Inf;//!
}