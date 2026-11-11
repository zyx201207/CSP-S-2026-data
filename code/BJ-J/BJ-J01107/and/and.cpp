#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10,M = 1e7 + 10;
int n,m,a[N];
bool flag[M];
int anss;
int maxx = INT_MIN;
int qpow(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}
int final_ans = INT_MIN;
void dfs(int step)
{
    if(step == m)
    {
        int ans;
        for(int i = 0;i < m;i++)
        {
            if(i == 1) ans = a[i];
            else ans &= a[i];
        }
        final_ans = max(final_ans,ans);
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!flag[a[i]])
        {
            a[step] = a[i];
            flag[a[i]] = 1;
            dfs(step + 1);
            flag[a[i]] = 0;
        }
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxx = max(maxx,a[i]);
        if(i == 1) anss = a[i];
        else anss &= a[i];
    }
    if(m == 1)
    {
        cout << maxx;
        return 0;
    }
    if(m == n)
    {
        cout << anss;
        return 0;
    }
    if(m == 2)
    {
        int ans = INT_MIN;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    int cnt = 0,cntt = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 21;j++)
        {
            if(qpow(2,j) - 1 == a[i])
            {
                cnt++;
                break;
            }
        }
        if(a[i] == i - 1) cntt++;
    }
    if(cnt == n)
    {
        stable_sort(a + 1,a + 1 + n,greater<int>());
        cout << a[m];
        return 0;
    }
    if(cntt == n && qpow(2,log2(n)) == n)
    {
        int ans;
        stable_sort(a + 1,a + 1 + n,greater<int>());
        for(int i = 1;i <= m;i++)
        {
            if(i == 1) ans = a[i];
            else ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    dfs(0);
    cout << final_ans;
    return 0;
}
