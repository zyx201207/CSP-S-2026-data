#include <bits/stdc++.h>
using namespace std;
int a[100005],c[100005],n,m,ans = 1;
int main()
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = a[i + 1] - a[i];
    }
    int l = 0;
    for (int i = 1; i <= n; i++)
    {
        l += c[i];
        if (l > m)
        {
            break;
        }
        else
        {
            a[i] = a[i + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(a[i + 1] == a[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
