#include <bits/stdc++.h>
using namespace std;
int a[1000000],m;
int main()
{
    //freopen ("and.in","r",stdin);
    //freopen ("and.out","w",stdout);
    int n;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    if (m = 1)
    {
        cout << a[n];
    }
    int ans;
    if (m == n)
    {
        for (int i = 2;i <= n;i++)
        {
            ans = (a[1]&a[i]);
        }
        cout << ans;
    }
    return 0;
}
