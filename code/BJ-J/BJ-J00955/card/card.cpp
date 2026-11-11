#include <bits/stdc++.h>
using namespace std;

int n,m,pos;
int a[500005],ans[300005];
int tmp[500005];
bool vis[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    for (int t = 1;t <= n;t ++)
    {
        pos = 0;
        for (int i = 1;i <= n;i ++)
        {
            tmp[i] = 0;
        }
        for (int i = 1;i <= m;i ++)
        {
            vis[i] = false;
        }

        for (int i = t;i <= n;i ++)
        {
            if(!vis[a[i]])
            {
                pos ++;
                tmp[pos] = a[i];
                vis[a[i]] = true;
            }
            else
            {
                while(true)
                {
                    if (tmp[pos] == a[i])
                    {
                        break;
                    }
                    else
                    {
                        vis[tmp[pos]] = false;
                        pos --;
                    }
                }

            }
        }
        for (int i = 1;i <= m;i ++)
        {
            if (vis[i])
            {
                ans[i] ++;
            }
        }
    }
    for (int i = 1;i <= m;i ++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
