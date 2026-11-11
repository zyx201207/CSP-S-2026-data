#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int n, m, a[200005], nas = 0;
int pre[200005], suf[200005];
bool use[200005];

bool checkA()
{
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 0, k = 1; j <= 30; j++, k <<= 1)
        {
            if (a[i] + 1 == k)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return false;
    }
    return true;
}

bool checkB()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != i - 1)
            return false;
    for (int i = 0, j = 1; i <= 30; i++, j <<= 1)
        if (j == n)
            return true;
    return false;
}

void dfs(int id, int cnt)
{
    if (cnt > m)
        return ;
    if (id > n)
    {
        if (cnt != m)
            return ;
        int res = (1ll << 40) - 1;
        for (int i = 1; i <= n; i++)
            if (use[i])
                res &= a[i];
        nas = max(nas, res);
        return ;
    }
    use[id] = true;
    dfs(id + 1, cnt + 1);
    use[id] = false;
    dfs(id + 1, cnt);
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int stask = 0;
    if (n <= 20) stask = 1;
    else if (n <= 2000 && m == 1) stask = 2;
    else if (n <= 2000 && m == n) stask = 3;
    else if (n <= 2000 && m == 2) stask = 4;
    else if (m == n - 1) stask = 5;
    else if (checkA()) stask = 6;
    else if (checkB()) stask = 7;
    else if (*max_element(a + 1, a + 1 + n) < 4) stask = 8;
    else stask = 9;
    if (stask == 1)
    {
        dfs(1, 0);
        cout << nas;
    }
    else if (stask == 2)
    {
        cout << *max_element(a + 1, a + 1 + n);
    }
    else if (stask == 3)
    {
        for (int i = 1; i <= n; i++)
            nas &= a[i];
        cout << nas;
    }
    else if (stask == 4)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j)
                    nas = max(nas, a[i] & a[j]);
        cout << nas;
    }
    else if (stask == 5)
    {
        pre[0] = (1ll << 40) - 1;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] & a[i];
        suf[n + 1] = (1ll << 40) - 1;
        for (int i = n; i >= 1; i--)
            suf[i] = suf[i + 1] & a[i];
        for (int i = 1; i <= n; i++)
            nas = max(nas, pre[i - 1] & suf[i + 1]);
        cout << nas;
    }
    else if (stask == 6 || stask == 7)
    {
        sort(a + 1, a + 1 + n, greater<int>());
        nas = (1ll << 40) - 1;
        for (int i = 1; i <= m; i++)
            nas &= a[i];
        cout << nas;
    }
    else if (stask == 8 || stask == 9) // idk
    {
        sort(a + 1, a + 1 + n, greater<int>());
        nas = (1ll << 40) - 1;
        for (int i = 1; i <= m; i++)
            nas &= a[i];
        cout << nas;
    }
    return 0;
}