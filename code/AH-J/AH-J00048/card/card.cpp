#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], cnt[300005];
bool use[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    if (m == 1)
    {
	cout << n;
	return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        stack<int> st;
        for (int j = i; j <= n; ++j)
        {
            if (use[a[j]])
            {
                while (st.top() != a[j] && !st.empty())
                {
                    int x = st.top();
                    st.pop();
                    use[x] = false;
                }
            }
            else
            {
                st.push(a[j]);
                use[a[j]] = true;
            }
        }
        for (int j = 1; j <= m; ++j)
        {
            cnt[j] += use[j];
            use[j] = false;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        cout << cnt[i] << " ";
    }

    return 0;
}
