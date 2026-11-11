#include <iostream>
using namespace std;

int n , m , a[500005] , cnt[300005] , vis[300005] , s[500005];

int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = 1; j <= m; j++)
        {
            vis[j] = 0;
        }
        for (int j = i; j <= n; j++)
        {
            if (!vis[a[j]])
            {
                cnt[a[j]]++;
                vis[a[j]] = 1;
                s[++cur] = a[j];
            }
            else
            {
                int f = 0 , x = 0;
                for (int k = 1; k <= cur; k++)
                {
                    if (f)
                    {
                        x++;
                        cnt[s[k]]--;
                        vis[s[k]] = 0;
                        s[k] = 0;
                    }
                    if (s[k] == a[j])
                    {
                        f = 1;
                    }
                }
                cur -= x;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
