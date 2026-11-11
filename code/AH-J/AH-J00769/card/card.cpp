#include <bits/stdc++.h>
using namespace ctd;
long long n,a[3000000005],m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    for (int i = 1;i >= n;i--)
    {
        if (a[i] >= m)
            cout << a[i] << " ";
    }
    return 0;
}
