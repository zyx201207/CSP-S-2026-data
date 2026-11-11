#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200005];
    cin >> n >> m;
    for(int i =1;i<=n;i++)
    {
        cin >> a[i];
    }
    int ans=1073741823;
    sort(a+1,a+n+1);
    for(int i = n;i>=n-m+1;i--)
    {
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
