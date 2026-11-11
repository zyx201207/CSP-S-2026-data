#include <bits/stdc++.h>
using namespace std;

long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

long long n, m, a[500010], ans[300010], cnt[300010];
bool vis[300010], flagA = 0;
stack<int> st;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    n = read(), m = read();
    flagA = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (flagA && a[i - 1] > a[i]) flagA = 0;
    }
    if (flagA)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt[a[i]]++;
        }
        for (int i = 1; i <= m; i++)
        {
            ans[i] = ans[i - 1] + cnt[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof vis);
            for (int j = i; j <= n; j++)
            {
                if (vis[a[j]])
                {
                    while (st.top() != a[j])
                    {
                        vis[st.top()] = 0;
                        st.pop();
                    }
                    st.pop();
                }
                st.push(a[j]);
                vis[a[j]] = 1;
            }
            while (!st.empty())
            {
                ans[st.top()]++;
                st.pop();
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%lld ", ans[i]);
    }
    return 0;
}
