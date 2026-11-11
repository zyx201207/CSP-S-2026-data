#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    scanf("%lld %lld", &n, &m);
    //cout << n << ' ' << m << endl;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    int l = 1;
    int res = 0;
    int sum = 0;
    for(int r = 1; r <= n; r++)
    {
        //cout << 1 << endl;
        sum += (r - l) * (a[r] - a[r-1]);
        while(sum > m && l <= r)
        {
            sum -= (a[r] - a[l]);
            l++;
        }
        res = max(res, r - l + 1ll);
        //cout << res << endl;
    }
    cout << res << endl;
    return 0;
}
