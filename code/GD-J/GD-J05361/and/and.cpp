#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ans = -0x3f3f3f3f;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            ans = max((a[i] & a[j]),ans);
        }
    }
    cout << ans;
}
