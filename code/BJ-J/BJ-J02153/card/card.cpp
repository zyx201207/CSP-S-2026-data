#include <bits/stdc++.h>
using namespace std;

int a[200005], ans[200005];
bool on[200005];
stack<int> st;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        memset(on, false, sizeof(on));
        for (int j = i; j <= n; ++j)
        {
            if (on[a[j]] == false) st.push(a[j]), on[a[j]] = true;
            else
            {
                while (st.top() != a[j]) st.pop();
            }
        }
        while (!st.empty())
        {
            ans[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
    return 0;
}
