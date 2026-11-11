#include <bits/stdc++.h>
using namespace std;
int a[25],e[25],fan[25];
int n,sum,m;
int ans = 12;
int ec[25][80];
int maxx = -1;
bool flag;
int zhuan (int x)
{
    int t = 0;
    int num = 0;
    int re = 0;
    while (x > 0)
    {
        fan[t] = x % 2;
        x /= 2;
        t++;
        num++;
    }
    for (int i = num;i >= 0;i--)
    {
        re = re * 10 + fan[i];
    }
    return re;
}
int ce (int x,int y)
{
    int j = 1;
    while (x>0)
    {
        ec[y][j] = x%10;
        x /= 10;
        j++;
    }
    if (maxx > j)
    {
        maxx = j;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        e[i] = zhuan(a[i]);
        ce(e[i],i);
    }
    sort (a+1,a+n+1);
    for (int i = 1;i <= n;i++)
    {
        e[n+i] = zhuan(a[i]);
        ce(e[n+i],i);
    }
    for (int i = 1;i <= n;i++)
    {
        sum = 0;
        for (int h = 1;h <= maxx;h++)
        {
            flag = true;
            for (int j = 0;j <= m-1;j++)
            {
                if (ec[i+j][h] == 0)
                {
                    flag = false;
                }
                if (j == m-1 && flag == true)
                {
                    sum++;
                }
            }
            if (sum > ans)
            {
                ans = sum;
            }
        }
    }
    cout << ans;
    return 0;
}
