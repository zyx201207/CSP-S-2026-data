#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans[N], vis[N];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int lc = 1; lc <= n; lc++)
    {
        for (int i = lc-1; i <= n; i++)
            vis[a[i]] = 0;
        stack<int> st;
        for (int i = lc; i <= n; i++)
        {
            if (!vis[a[i]])
            {
                st.push(a[i]);
                vis[a[i]] = 1;
            }
            else
            {
                while (!st.empty() && st.top() != a[i])
                {
                    vis[st.top()] = 0;
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            ans[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
