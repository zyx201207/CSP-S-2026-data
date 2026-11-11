#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],m,sum,ans = -99999;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n - m + 1;i++)
    {
        sum = a[i];
        for (int j = i + 1;j <= i + m - 1;j++)
        {
            sum = sum & a[j];
        }
        ans = max(sum,ans);
    }
    cout << ans;
    return 0;
}
