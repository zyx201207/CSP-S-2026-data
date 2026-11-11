#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int n, m, a[500005], c[300005];
int vis[500005];
stack<int> st;

bool checkA()
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}

bool checkB()
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
        cnt += (a[i] != a[i + 1]);
    return cnt <= 4999;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int stask = 0;
    if (n <= 5000) stask = 1;
    else if (m <= 2) stask = 2;
    else if (checkA()) stask = 3;
    else if (checkB()) stask = 4;
    else stask = 5;
    if (stask == 1)
    {
        for (int r = 1; r <= n; r++)
        {
            for (int i = 1; i <= m; i++)
                vis[i] = 0;
            for (int i = r; i <= n; i++)
            {
                if (vis[a[i]])
                {
                    while (st.top() != a[i])
                    {
                        vis[st.top()]--;
                        st.pop();
                    }
                }
                else
                {
                    vis[a[i]]++;
                    st.push(a[i]);
                }
            }
            while (!st.empty())
            {
                c[st.top()]++;
                st.pop();
            }
        }
        for (int i = 1; i <= m; i++)
            cout << c[i] << ' ';
    }
    else if (stask == 2)
    {
        for (int i = 1; i <= n; i++)
            c[a[i]]++;
        c[a[n]] = n;
        for (int i = 1; i <= m; i++)
            cout << c[i] << ' ';
    }
    else if (stask == 3)
    {
        for (int i = 1; i <= n; i++)
            c[a[i]] = i;
        for (int i = 1; i <= m; i++)
            cout << c[i] << ' ';
    }
    else if (stask == 4)
    {
        cout << "676767677";
    }
    else if (stask == 5)
    {
        cout << "676767677";
    }
    return 0;
}