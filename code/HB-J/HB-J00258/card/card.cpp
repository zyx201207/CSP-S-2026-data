#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005];
bool on[300005];
int ans[300005];

void solve1()
{
    for (int i = 1; i <= n; i++)
    {
        stack<int> st;
        memset(on, 0, sizeof(on));
        for (int j = i; j <= n; j++)
        {
            int k = a[j];
            if (!on[k])
            {
                st.push(k);
                on[k] = true;
            }
            else
            {
                while (!st.empty() && st.top() != k)
                {
                    on[st.top()] = false;
                    st.pop();
                }

            }
        }
        for (int j = 1; j <= m; j++)
            if (on[j]) ans[j]++;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve1();
    return 0;
}
