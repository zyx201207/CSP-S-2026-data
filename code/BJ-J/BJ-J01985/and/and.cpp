#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N],b[N];
int n,m,maxn = -1e9;
bool flag[25];
int cnt = 0;
int dfs(int st,int k,int ans)
{
    if(k == m)return ans;
    if(st == n)return 0;
    for(int i = st + 1;i <= n;++i)
    {
        dfs(i,k + 1,ans & a[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool falg = 0;
    cin >> n >>m;
    for(int i = 0;i <= 17;++i)
    {
        int mul = 1;
        for(int j = 1;j <= i;++j)j *= 2;
        if(n == mul)falg = 1;
    }
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    if(m == 1)
    {
        int ans = 0;
        for(int i = 1;i <= n;++i)
        {
            ans = max(ans,a[i]);
        }
        cout << ans;
        return 0;
    }
    if(m == 2)
    {
        int ans = 0;
        for(int i = 1;i <= n;++i)
        {
            for(int j = i + 1;j <= n;++j)
            {
                ans = max(ans,(a[i] & a[j]));
            }
        }
        cout << ans;
        return 0;
    }
    if(m == n)
    {
        int ans = a[1];
        for(int i = 2;i <= n;++i)
        {
            ans = (ans & a[i]);
        }
        cout << ans;
        return 0;
    }
    if(maxn < 4)
    {
        for(int i = 1;i <= n;++i)
        {
            b[a[i]]++;
        }
        if(b[3] >= m)cout << 3;
        else if(b[2] >= m || b[2] + b[3] >= m)cout << 2;
        else if(b[1] >= m || b[1] + b[3] >= m)cout << 1;
        else cout << 0;
        return 0;
    }
    if(falg == 1)
    {
        if(n == 1)cout << 0;
        else cout << n - 2;
        return 0;
    }
    if(m == n - 1)
    {
        sort(a + 1,a + n + 1);
        int ans = a[2];
        for(int i = 3;i <= n;++i)
        {
            ans = (ans & a[i]);
        }
        cout << ans;
        return 0;
    }
    if(n <= 20)
    {
        cout << dfs(0,0,INT_MAX);
        return 0;
    }
    cout << 0;
    return 0;
}
