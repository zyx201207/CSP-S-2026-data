#include <bits/stdc++.h>
using namespace std;

bool d(int i)
{
    if (i % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int a[100005],b[100005];
    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }

    int maxn = -1e9;

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (a[i] != a[j])
            {
                maxn = max(a[i]&a[j],maxn);
            }
        }
    }
    cout << maxn;

    return 0;
}
