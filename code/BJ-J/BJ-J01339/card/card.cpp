#include <iostream>
#include <cstring>
using namespace std;
bool ok[5005];
int pos[3005];
int a[5005];
int ans[3005];
int p[3005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ok[j] = 1;
            if (pos[a[j]] == 0)
            {
                pos[a[j]] = j;
            }
            else
            {
                for (int k = pos[a[j]];k <= j - 1; k++ )
                {
                    ok[k] = 0;
                    pos[a[k]] = 0;
                }
                pos[a[j]] = j;
            }
        }
        for (int j = i; j <= n; j++)
        {
            if (ok[j] == 1 && p[a[j]] == 0)
            {
                ans[a[j]]++;
                p[a[j]] = 1;
            }
        }
        memset(p,0,sizeof(p));
        memset(pos,0,sizeof(pos));
        memset(ok,0,sizeof(ok));
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
