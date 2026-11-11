#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n , m , a[N] , suma[N];
signed main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    for(int i = 1; i <= n; i++) suma[i] = suma[i - 1] + a[i];
    int l = 1 , r = 1;
    int nown = 0 , ans = 1;
    while(l <= r && l <= n && r <= n)
    {
        //cout << l << " " << r << endl;
        if(r >= n || l >= n || l > r) break;
        nown = a[r] * (r - l + 1) - suma[r] + suma[l - 1];
        while(r <= n && nown <= m)
        {
            r++;
            nown = a[r] * (r - l + 1) - suma[r] + suma[l - 1];
        }
        r--;
        ans = max(ans , r - l + 1);
        l++;r++;
    }
    cout << ans << endl;
    return 0;
}
//r * len - sum l~r
//l , r
