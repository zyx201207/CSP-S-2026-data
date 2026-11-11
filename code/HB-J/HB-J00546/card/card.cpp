#include <bits/stdc++.h>
using namespace std;
int t[500005], cnt[500005];
bool cmp[500005];
stack<int> st;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (cmp[t[j]])
            {
                while (st.top() != t[j])
                {
                    cmp[st.top()] = 0;
                    st.pop();
                }
            }
            else
            {
                cmp[t[j]] = 1;
                st.push(t[j]);
            }
        }
        while (!st.empty())
        {
            cnt[st.top()] ++;
            cmp[st.top()] = 0;
            st.pop();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
