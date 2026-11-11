#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], ans[300005];
bool box[300005], flaga = 1;
stack <int> st, st2;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) flaga = 0;
    }
    if (flaga)
    {
        for (int i = n; i >= 1; i--)
        {
            if (box[a[i]] == 0) ans[a[i]] = i;
            box[a[i]] = 1;
        }
        for (int i = 1; i <= m; i++) cout << ans[i] << " ";
        return 0;
    }
    for (int i = n; i >= 1; i--)
    {
        if (box[a[i]])
        {
            while (st.top() != a[i])
            {
                box[st.top()] = 0;
                st.pop();
            }
            box[st.top()] = 0;
            st.pop();
        }
        box[a[i]] = 1;
        st.push(a[i]);
        while (!st.empty())
        {
            ans[st.top()]++;
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
