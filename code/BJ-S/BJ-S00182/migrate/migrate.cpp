#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[2000005];
int dis = 1e9;
int d;
int ans;
int n;
int tar;

void dfs(int pos, int cs, int dis_lx)
{
    if (pos == tar)
    {
        dis = min(dis, cs);
        return;
    }
    if (cs >= dis)
    {
        return;
    }
    int temp = pos + 1;
    dfs(pos, cs + 1, 0);
    while (a[temp] - a[pos] + dis_lx <= d)
    {
        dfs(temp, cs, dis_lx + a[temp] - a[pos]);
        if (temp >= tar)
        {
            break;
        }
        temp++;
    }
    return;
}

void dfs2(int pos, int cs, int dis_lx)
{
    if (pos == tar)
    {
        if (cs == dis)
        {
            ans++;
        }
        return;
    }
    if (cs > dis)
    {
        return;
    }
    int temp = pos + 1;
    dfs(pos, cs + 1, 0);
    while (a[temp] - a[pos] + dis_lx <= d)
    {
        dfs(temp, cs, dis_lx + a[temp] - a[pos]);
        if (temp >= tar)
        {
            break;
        }
        temp++;
    }
    return;
}


int main()
{
    int c, t;
    cin >> c;
    cin >> t;
    while (t--)
    {
        int sum = 0;
        cin >> n;
        cin >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = 0;
                dis = 1e9;
                tar = j;
                dfs(i, 0, 0);
                dfs2(i, 0, 0);
                if (ans == 2)
                {
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
