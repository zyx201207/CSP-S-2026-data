#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[300005],p[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        memset(p,-1,sizeof(p));
        for (int j = i;j <= n;j++)
        {
            if (p[a[j]] != -1)
            {
                for (int k = p[a[j]];k <= j;k++)
                {
                    p[a[k]] = -1;
                }
            }
            p[a[j]] = j;
        }
        for (int i = 1;i <= m;i++)
        {
            if (p[i] != -1)
            {
                c[i]++;
            }
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
