#include <bits/stdc++.h>
using namespace std;

int a[500005];
bool flag[300005];
int ans[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        memset(flag, 0, sizeof(flag));
        stack<int> st;
        for (int j = i; j <= n; j++)
        {
            if (!flag[a[j]])
            {
                st.push(a[j]);
                flag[a[j]] = 1;
            }
            else
            {
                while(1)
                {
                    if(st.top() == a[j] || st.size() == 0)
                    {
                        break;
                    }
                    flag[st.top()] = 0;
                    st.pop();
                }
            }
        }
        while(1)
        {
            if (st.size() == 0)
            {
                break;
            }
            ans[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
