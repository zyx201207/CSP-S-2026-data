#include <bits/stdc++.h>
using namespace std;
int n,ans,mid;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    if (n%2 == 0)
        mid = n/2;
    else
        mid = n/2+1;
    int d = a[1]-a[0],c=1;
    for (int i = 1;i < mid;i++)
    {
        m -= c*d;
        c++;
        if (m < 0)
            break;
        ans++;
    }
    cout << ans+1;
    return 0;
}