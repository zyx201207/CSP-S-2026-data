#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >>m;
    for (int i = 1;i <= n;i++)
    {

        cin >> a[i];
        ans = max(ans,a[i]);
    }
    if (m == 1)
    {

        cout << ans;
        return 0;
    }
    cout << (a[2] ^ a[1]);
    return 0;
}
