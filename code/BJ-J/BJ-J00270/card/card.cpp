#include <iostream>
#include <cstdio>

using namespace std;

int n, m, a[514514];
int nxt[514514], fnxt[514514], nxtn[514514];
int cf[514514];//chafen
int ans[514514];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = n; i >= 1; i--)
    {
        if (fnxt[a[i]] > 0)
        {
            nxt[i] = fnxt[a[i]];
        }
        else fnxt[a[i]] = i;
    }
    for (i = n; i >= 1; i--)
    {
        if (nxt[i] > 0)
        {
            nxtn[i] = i;
        }
        else nxtn[i] = nxtn[i + 1];
    }
    int ff = 0, fff = 0;
    for (i = n; i >= 1; i--)
    {
        int j = i;
        while (j != 0)
        {
            cf[j]++;
            cf[nxtn[j]]--;
            j = nxt[nxtn[j]];
        }
    }
    cf[0] = 0;
    for (i = 1; i <= n; i++)
    {
        cf[i] += cf[i - 1];
        ans[a[i]] += cf[i];
    }
    cout << ans[1];
    for (i = 2; i <= m; i++)
    {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
