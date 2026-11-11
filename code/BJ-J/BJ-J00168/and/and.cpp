#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int ans=a[n];
    for (int i=n-1;i>=n-k+1;i--)
    {
        ans&=a[i];
    }
    cout << ans;
}
