#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,m,a[N],prefix[N],ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    stable_sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++)
    {
       prefix[i] = prefix[i - 1] + a[i];
    }
    for(int i = 1;i <= n;i++)
        if((i - 1) * a[i] - prefix[i - 1] <= m)
            ans = i;
    cout << ans;
    return 0;
}
