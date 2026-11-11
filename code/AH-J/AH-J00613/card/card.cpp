#include <bits/stdc++.h>
using namespace std;
int n,a[500005],m,b[500005];
int f[500005],ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int top = 0;
        for(int j = i;j <= n;j++)
        {
            if(f[a[j]] != 0)
            {
                top = f[a[j]] - 1;
            }
            b[++top] = a[j];
            f[a[j]] = top;
        }
        for(int j = 1;j <= m;j++)
        {
            for(int k = 1;k <= n;k++)
            {
                if(b[k] == j)
                    ans[j]++;
            }
        }
        for(int k = 1;k <= m;k++)
            f[k] = 0;
    }
    for(int i = 1;i <= m;i++)
            cout << ans[i] << ' ';
    return 0;
}
