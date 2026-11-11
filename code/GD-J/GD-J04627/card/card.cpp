#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans[300005];
int b[500005];
int m = 0, n = 0;
void check(int x)
{
    int temp = 0;
    int tem = 0;
    bool a[300005] = {0};
    for (int j = x; j <= n; j++)
    {
        if (a[b[j]])
        {
            temp = j;
            tem = b[j];
            do
            {
                a[b[j]] = false;
                j--;
            } while (b[j] != b[tem]);
            j = temp;
        }
        else
        {
            a[b[j]] = true;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        if (a[k] == true)
            ans[k]++;
    }
}

bool baolizha()
{
    int g = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > b[i - 1])
        {
            g++;
        }
    }
    if (g == n)
    {
        for (int i = m; i >= 0; i--)
        {
            cout << i << ' ';
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        b[i] = temp;
    }
    if (baolizha())
    {
        return 0;
    };
    for (int i = 1; i <= n; i++)
    {
        check(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
