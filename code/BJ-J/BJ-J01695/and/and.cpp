#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];

int flag[200005];
int maxn = 0;

bool cmp(int a, int b)
{
    return a > b;
}

void dfs(int x, string s)
{
    if (x == m)
    {
        int ans = a[int(s[0] - '0')];
        for (int i = 1; i < m; i++)  //work out anweiyu
        {
            ans &= a[int(s[i] - '0')];
        }

        //ceshi
        //cout << s << " " << ans << endl;


        maxn = max(ans, maxn);
        return;
    }
    if (x == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            dfs(x + 1, s + char(i + '0'));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (int(s[x - 1] - '0') < i)
        {
            dfs(x + 1, s + char(i + '0'));
        }
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (m == 1)
    {
        sort(a + 1, a + n + 1, cmp);//jiangxu
        cout << a[1];
        return 0;
    }

    if (m == n)
    {
        int ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans &= a[i];
        }
        cout << ans << endl;
        return 0;
    }

    if (m == (n - 1))
    {
        int maxn = 0;
        for (int i = 1; i <= n; i++) // dont to care i
        {
            int ans = a[1];
            for (int j = 2; j <= n; j++)//quan jia qi lai
            {
                if (j != i) ans &= a[j];
            }
            maxn = max(maxn, ans);
        }
        cout << maxn << endl;
        return 0;
    }

    if (m == 2)
    {
        int maxn = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == i) continue;

                maxn = max(maxn, a[i] & a[j]);
            }
        }

        cout << maxn << endl;
        return 0;
    }
    if (n <= 20)
    {
        dfs(0, ""); //bianli choosing m number to work out
        cout << maxn << endl;
        return 0;
    }

    //teshuxingzhi B
    bool bflag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != (i - 1)) bflag = 0;
    }

    if (bflag)
    {
        int ans = a[n - m + 1];
        for (int i = n - m + 2; i <= n; i++)
        {
            ans &= a[i];
        }

        cout << ans << endl;
        return 0;
    }
    
    // 16-17
    

    //teshuxingzhi A
    sort(a + 1, a + n + 1, cmp);//jiangxu
    cout << a[m] << endl;

    return 0;
}